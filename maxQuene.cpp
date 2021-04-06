
#include "QueueMax.h"


//队列的最大值https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/ 

int QueueMax::max_value() {

    if (d.empty()) {
        return -1;
    }
    return d.front();
}
/**
 * 往队列插入数据
 * @param value
 */
void QueueMax::push_back(int value) {
    q.push(value);

    while (!d.empty() && d.back() < value) {
        d.pop_back();
    }

    d.push_back(value);

}

int QueueMax::pop_front() {

    if (q.empty()) {
        return -1;
    }
    int qFront = q.front();

    if (qFront == d.front()) {
        d.pop_front();
    }
    q.pop();
    return qFront;
}
