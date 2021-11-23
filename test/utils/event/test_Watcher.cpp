#include <atomic>
#include <thread>

#include "gtest/gtest.h"
#include "glwpp/utils/event/Watcher.hpp"

TEST(test_Watcher, lock_use){
    glwpp::Watcher watcher;

    watcher.lock_use();
    EXPECT_EQ(watcher.get_uses(), 1);
    watcher.unlock_use();
    EXPECT_EQ(watcher.get_uses(), 0);
};

TEST(test_Watcher, lock_running){
    glwpp::Watcher watcher;

    watcher.lock_running();
    EXPECT_EQ(watcher.get_running(), 1);
    EXPECT_EQ(watcher.is_idle(), false);

    watcher.unlock_running(false);
    EXPECT_EQ(watcher.get_running(), 0);
    EXPECT_EQ(watcher.is_idle(), true);
    EXPECT_EQ(watcher.get_done(), 0);

    watcher.lock_running();
    EXPECT_EQ(watcher.get_running(), 1);
    EXPECT_EQ(watcher.is_idle(), false);

    watcher.unlock_running(true);
    EXPECT_EQ(watcher.get_running(), 0);
    EXPECT_EQ(watcher.is_idle(), true);
    EXPECT_EQ(watcher.get_done(), 1);
}

TEST(test_Watcher, wait_for_idle){
    glwpp::Watcher watcher;
    std::atomic<bool> started = false;
    std::atomic<bool> finished = false;

    watcher.lock_running();
    std::thread([&watcher, &started, &finished](){
        started = true;
        watcher.wait_for_idle();
        finished = true;
    }).detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    EXPECT_EQ(started.load(), true);
    EXPECT_EQ(finished.load(), false);

    watcher.unlock_running(false);

    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    EXPECT_EQ(finished.load(), true);
};

TEST(test_Watcher, wait_for_done){
    glwpp::Watcher watcher;
    std::atomic<bool> started = false;
    std::atomic<bool> finished = false;

    watcher.lock_running();
    watcher.lock_running();
    std::thread([&watcher, &started, &finished](){
        started = true;
        watcher.wait_for_done();
        finished = true;
    }).detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    EXPECT_EQ(started.load(), true);
    EXPECT_EQ(finished.load(), false);

    watcher.unlock_running(false);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    EXPECT_EQ(finished.load(), false);

    watcher.unlock_running(true);

    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    EXPECT_EQ(finished.load(), true);
};

TEST(test_Watcher, free_waiters_on_destroy){
    {
        glwpp::Watcher watcher;
        watcher.lock_running();
        std::thread([&watcher](){
            watcher.wait_for_done();
        }).detach();
    }
    
    {
        glwpp::Watcher watcher;
        watcher.lock_running();
        std::thread([&watcher](){
            watcher.wait_for_idle();
        }).detach();
    }
};
