#ifndef NETWORKPROGRAMMING_H
#define NETWORKPROGRAMMING_H

#include <iostream>
#include <boost/asio.hpp>
#include <thread>

using boost::asio::ip::tcp;

void runServer(short port) {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));
    std::cout << "Server running on port " << port << "\n";

    while (true) {
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        std::string message = "Hello from Server!";
        boost::system::error_code ignored_error;
        boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
    }
}

void runClient(const std::string& host, short port) {
    boost::asio::io_context io_context;
    tcp::socket socket(io_context);
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string(host), port));

    boost::array<char, 128> buf;
    boost::system::error_code error;

    size_t len = socket.read_some(boost::asio::buffer(buf), error);
    if (!error) {
        std::cout << "Server responded: " << std::string(buf.data(), len) << "\n";
    } else {
        std::cout << "Error during receive: " << error.message() << "\n";
    }
}

void runNetworkProgramming() {
    std::thread serverThread(runServer, 1234);
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait for the server to set up
    std::thread clientThread(runClient, "127.0.0.1", 1234);

    serverThread.join();
    clientThread.join();
}

#endif
