
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *dummy= new ListNode(0, head), *p0 = dummy;
    int i = 1;
    while(i < left) {
        p0 = p0->next;
        i++;
    }

    ListNode *cur = p0->next, *pre = nullptr, *nxt;
    while(i <= right) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
        i++;
    }

    p0->next->next = cur;
    p0->next = pre;
    return dummy->next;
}

