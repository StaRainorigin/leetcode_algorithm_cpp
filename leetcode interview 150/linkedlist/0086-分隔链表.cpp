struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* partition(ListNode* head, int x) {
    ListNode *dummy1 = new ListNode(0), *dummy2 = new ListNode(0);
    ListNode *p0 = head, *p1 = dummy1, *p2 = dummy2;
    while(p0) {
        if (p0->val < x) {
            p1->next = p0;
            p1 = p1->next;
        } else {
            p2->next = p0;
            p2 = p2->next;
        }
        p0 = p0->next;
    }
    p1->next = dummy2->next;
    p2->next = nullptr;
    return dummy1->next;
}