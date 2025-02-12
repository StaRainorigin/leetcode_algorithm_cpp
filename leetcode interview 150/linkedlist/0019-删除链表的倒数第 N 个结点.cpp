struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head, *dummy = new ListNode(0, head), *slow = dummy;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    while(fast) {
        fast = fast->next;
        slow = slow->next;
    }
    fast = slow->next->next;
    slow->next = fast;
    return dummy->next;
}