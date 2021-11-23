#include <atomic>
#include <iostream>
#include <thread>

#include "gtest/gtest.h"
#include "glwpp/utils/event/Runner.hpp"

using namespace glwpp;

TEST(test_Runner, run){
    auto watcher = make_sptr<Watcher>();
    auto runner = make_sptr<Runner<int()>>(watcher, [](){
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
        return 0;
    });

    EXPECT_EQ(watcher->get_uses(), 1);

    std::atomic<bool> started = false;
    std::thread([&started, &runner](){
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
        started = true;
        started.notify_one();
        runner->run();
    }).detach();

    watcher->wait_for_runnings_change();

    EXPECT_EQ(watcher->get_running(), 1);
    EXPECT_EQ(watcher->get_done(), 0);

    watcher->wait_for_done();

    EXPECT_EQ(watcher->get_running(), 0);
    EXPECT_EQ(watcher->get_done(), 1);

    runner.reset();
    EXPECT_EQ(watcher->get_uses(), 0);
};

TEST(test_Runner, capture_exception){
    auto watcher = make_sptr<Watcher>();
    auto runner = make_sptr<Runner<int(int, float)>>(watcher, [](int v){
        if (v < 5)
            return 3;
        else
            throw std::runtime_error("OK");
    });

    {
        std::variant<int, std::exception_ptr> res;
        std::thread([&runner, &res](){
            res = runner->run(0, 3.0);
        }).detach();

        watcher->wait_for_done();
        EXPECT_EQ(watcher->get_done(), 1);
        EXPECT_EQ(std::get<int>(res), 3);
    }

    {    
        std::variant<int, std::exception_ptr> res;
        std::thread([&runner, &res](){
            res = runner->run(10, 3.0);
        }).detach();

        std::this_thread::sleep_for(std::chrono::milliseconds(3));
        watcher->wait_for_idle();
        EXPECT_EQ(watcher->get_done(), 1);

        auto p_exc = std::get<std::exception_ptr>(res);
        EXPECT_THROW(std::rethrow_exception(p_exc), std::runtime_error);
    }
};