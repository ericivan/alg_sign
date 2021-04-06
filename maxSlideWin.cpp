//
// Created by Ericivan on 2021/4/1.
// 滑动窗口的最大值https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/ 

#include "vector"
#include "deque"
#include <iostream>

using namespace std;

class SlideWinMax {

public:

    vector<int> maxSlidingWindow(vector<int> &nums, int k) {

        if (nums.size() == 0 || k == 0) {
            return vector<int>({});
        }

        /*单调递减队列*/
        deque<int> d;
        int left = 1 - k;
        int right = 0;
        vector<int> output;
        int length = nums.size();

        while (right < length) {

            if (!d.empty() && left >= 1 && nums[left - 1] == d.front()) {
                d.pop_front();
            }

            while (!d.empty() && nums[right] > d.back()) {
                d.pop_back();
            }

            d.push_back(nums[right]);

            if (left >= 0) {
                output.push_back(d.front());
            }
            left++;
            right++;
        }

        this->printVector(output);

        return output;

    }

    template<class T>
    void printVector(vector<T> v) {
        for (typename vector<T>::iterator it = v.begin(); it < v.end(); it++) {
            cout << *it << "|";
        }

        cout << endl;
    }
};


