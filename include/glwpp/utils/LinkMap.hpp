#pragma once

#include <unordered_map>
#include <vector>

namespace glwpp {

template<class T1, class T2>
class LinkMap {
static_assert(!std::is_same_v<T1, T2>);

public:
    const std::vector<T2*>* get(T1 *t1){
        auto iter = _T1_T2.find(t1);
        if (iter == _T1_T2.end()){
            return nullptr;
        } else {
            return &iter->second;
        }
    };

    const std::vector<T1*>* get(T2 *t2){
        auto iter = _T2_T1.find(t2);
        if (iter == _T2_T1.end()){
            return nullptr;
        } else {
            return &iter->second;
        }
    };

    void add(T1 *t1, T2 *t2){
        auto iter1 = _T1_T2.find(t1);
        if (iter1 == _T1_T2.end()) iter1 = _T1_T2.insert({t1, {}}).first;
        iter1->second.push_back(t2);

        auto iter2 = _T2_T1.find(t2);
        if (iter2 == _T2_T1.end()) iter2 = _T2_T1.insert({t2, {}}).first;
        iter2->second.push_back(t1);
    }

    void remove(T1 *t1){
        auto t1_iter = _T1_T2.find(t1);
        if (t1_iter == _T1_T2.end()) return;

        auto &t2_list = t1_iter->second;
        for (auto t2_iter = t2_list.begin(); t2_iter != t2_list.end();){
            auto links = _T2_T1.find(*t2_iter);
            if (links == _T2_T1.end()) continue;

            auto &list = links->second;
            list.erase(std::remove(list.begin(), list.end(), t1), list.end());
            if (list.empty()){
                t2_iter = t2_list.erase(t2_iter);
            } else {
                ++t2_iter;
            }
        }
    }

    void remove(T2 *t2){
        auto t2_iter = _T2_T1.find(t2);
        if (t2_iter == _T2_T1.end()) return;

        auto &t1_list = t2_iter->second;
        for (auto t1_iter = t1_list.begin(); t1_iter != t1_list.end();){
            auto links = _T1_T2.find(*t1_iter);
            if (links == _T1_T2.end()) continue;

            auto &list = links->second;
            list.erase(std::remove(list.begin(), list.end(), t2), list.end());
            if (list.empty()){
                t1_iter = t1_list.erase(t1_iter);
            } else {
                ++t1_iter;
            }
        }
    }

    void remove(T1 *t1, T2 *t2){
        auto t1_iter = _T1_T2.find(t1);
        if (t1_iter != _T1_T2.end()){
            auto t1_list = t1_iter->second;
            t1_list.erase(std::remove(t1_list.begin(), t1_list.end(), t2), t1_list.end());
        };

        auto t2_iter = _T2_T1.find(t2);
        if (t2_iter != _T2_T1.end()){
            auto t2_list = t2_iter->second;
            t2_list.erase(std::remove(t2_list.begin(), t2_list.end(), t1), t2_list.end());
        };
    }

private:
    std::unordered_map<T1*, std::vector<T2*>> _T1_T2;
    std::unordered_map<T2*, std::vector<T1*>> _T2_T1;

    
};
    
}
