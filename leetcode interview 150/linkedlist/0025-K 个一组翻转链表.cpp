struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *dummy = new ListNode(0, head), *p0 = dummy;
    int count = 0;
    while(1) {
        ListNode *cur = p0->next, *pre, *nxt;
        while(count < k && cur) {
            cur = cur->next;
            count++;
        }
        if (count == k) {
            cur = p0->next;
            pre = nullptr;
            while(count > 0) {
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
                count--;
            }
            p0->next->next = cur;
            nxt = p0->next;
            p0->next = pre;
            p0 = nxt;
        } else {
            break;
        }
    }
    return dummy->next;
}

