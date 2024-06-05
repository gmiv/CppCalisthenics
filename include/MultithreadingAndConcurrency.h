#ifndef MULTITHREADINGANDCONCURRENCY_H
#define MULTITHREADINGANDCONCURRENCY_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> dataQueue;

void producer(int id) {
    for (int i = 0; i < 5; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        std::cout << "Producer " << id << " adding data " << i << "\n";
        dataQueue.push(i);
        lock.unlock();
        cv.notify_one();  // Notify one waiting thread
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void consumer(int id) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !dataQueue.empty(); });  // Wait until the queue is not empty
        int data = dataQueue.front();
        dataQueue.pop();
        std::cout << "Consumer " << id << " got data " << data << "\n";
        if (dataQueue.empty() && data == 4) break;  // Exit condition for simplicity
    }
}

void runMultithreadingAndConcurrency() {
    std::thread t1(producer, 1);
    std::thread t2(consumer, 1);
    t1.join();
    t2.join();
}

#endif
