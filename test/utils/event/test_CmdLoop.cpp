#include <atomic>
#include <thread>

#include "gtest/gtest.h"
#include "glwpp/utils/CmdLoop.hpp"

TEST(test_CmdLoop, construct){
    std::atomic<bool> inited = false;
    std::atomic<bool> destroyed = false;

    auto init = [&inited](glwpp::CmdLoop&){inited = true;};
    auto dest = [&destroyed](glwpp::CmdLoop&){destroyed = true;};

    {
        glwpp::CmdLoop loop(init, dest);
    }
    
    EXPECT_EQ(inited, true);
    EXPECT_EQ(destroyed, true);
};

TEST(test_CmdLoop, order){
    auto watcher = glwpp::make_sptr<glwpp::Watcher>();

    glwpp::CmdLoop loop;
    std::atomic<size_t> order = 0; 
    std::atomic<size_t> start = -1;
    std::atomic<size_t> run = -1;
    std::atomic<size_t> end = -1;

    loop.onLoopStart().push_back(watcher, [&start, &order](){
        start = order++;
        return glwpp::EventAction::Stop;
    });
    loop.onLoopRun().push_back(watcher, [&run, &order](){
        run = order++;
        return glwpp::EventAction::Stop;
    });
    loop.onLoopEnd().push_back(watcher, [&end, &order](){
        end = order++;
        return glwpp::EventAction::Stop;
    });

    loop.start();
    while (watcher->get_uses() > 0){
        watcher->wait_for_users_change();
    }
    
    EXPECT_EQ(start, 0);
    EXPECT_EQ(run, 1);
    EXPECT_EQ(end, 2);
};