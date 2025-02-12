struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    ListNode* cur = head, *ans;
    if (!head) return head;

    int length = 1;
    while (cur->next) {
        cur = cur->next;
        length++;
    }
    cur->next = head;

    int step = length - (k % length);
    cur = head;
    for (int i = 1; i < step; i++) {
        cur = cur->next;
    } 
    ans = cur->next;
    cur->next = nullptr;

    return ans;
}