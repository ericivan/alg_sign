#include <iostream>

using namespace std;

int main() {
  //两数相加：https://leetcode-cn.com/problems/add-two-numbers/
}


class ListNode {
public:
    ListNode *next;
    int val;

    ListNode(int val) {
        this->val = val;
    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *root = nullptr, *next = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!root) {
                root = next = new ListNode(sum % 10);
            } else {
                next->next = new ListNode(sum % 10);
                next = next->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            next->next = new ListNode(carry);
        }
        return root;
    }
};
