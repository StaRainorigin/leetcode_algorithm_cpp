#include <cstddef>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *p = l1, *q = l2, *dummy = new ListNode(0), *ans = dummy;
    size_t carry = 0;
    while(p || q || carry) {
        int l1_val = p ? p->val : 0;
        int l2_val = q ? q->val : 0;

        int sum = carry + l1_val + l2_val;
        carry = sum / 10;
        ans->next = new ListNode(sum % 10);
        ans = ans -> next;

        if(p) p = p->next;
        if(q) q = q->next;
    }
    return dummy->next;
}