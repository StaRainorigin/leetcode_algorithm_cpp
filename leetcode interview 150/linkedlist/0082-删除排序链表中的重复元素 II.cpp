#include <cmath>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates2(ListNode* head) { // 题解
    ListNode *dummy = new ListNode(0, head), *pre = dummy;
    while(pre->next && pre->next->next) {
        int val = pre->next->val;
        if (pre->next->next->val == val) {
            while (pre->next && pre->next->val == val) {
                pre->next = pre->next->next;
            }
        } else {
            pre = pre->next;
        }
    }
    return dummy->next;
}


ListNode* deleteDuplicates1(ListNode* head) { // 我自己
    ListNode *dummy = new ListNode(0, head), *pre = dummy, *cur = dummy->next;
    if (!cur) return dummy->next;
    ListNode *nxt = cur->next;
    while(nxt) {
        if (cur->val == nxt->val) {
            while (nxt && cur->val == nxt->val) {
                nxt = nxt->next;
                cur->next = nxt;
            }
            if(nxt) {
                cur = nxt;
                nxt = nxt->next;
                pre->next = cur;
            } else {
                pre->next = nullptr;
            }
        } else {
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
        }
    }
    return dummy->next;
}

