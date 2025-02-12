
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *p = list1, *q = list2, *dummy = new ListNode(0), *ans = dummy;
    while(p || q) {
        int num1 = p ? p->val : 101;
        int num2 = q ? q->val : 101;
        if (num1 < num2) {
            ans->next = new ListNode(num1);
            p = p->next;
        } else {
            ans->next = new ListNode(num2);
            q = q->next;
        }
        ans = ans->next;
    }
    return dummy->next;
}