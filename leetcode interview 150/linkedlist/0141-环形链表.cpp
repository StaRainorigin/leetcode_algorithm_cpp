
#include <cstddef>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    ListNode *p = head, *q = head;
    bool ans = false;
    while(q && q->next) {
        q = q->next->next;
        p = p->next;
        if (p == q) {
            ans = true;
            break;
        }
    }
    return ans;
}

int main() {

}