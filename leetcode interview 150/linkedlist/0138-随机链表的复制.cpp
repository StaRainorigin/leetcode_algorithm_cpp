#include <cstddef>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList1(Node* head) {
    unordered_map<Node*, Node*> maps;
    Node *p = head, *q = new Node(0), *dummy = q;

    while (p) {
        q->next = new Node(p->val);
        maps[p] = q->next; 
        p = p->next;
        q = q->next;
    }

    p = head, q = dummy->next;
    while (p) {
        if (p->random) {
            q->random = maps[p->random]; 
        }
        p = p->next;
        q = q->next;
    }

    return dummy->next; 
}

Node* copyRandomList2(Node* head) {
    Node *p = head, *q, *dummy = new Node(0);
    while (p) {
        q = new Node(p->val);
        q->next = p->next;
        p->next = q;
        p = p->next->next;
    }

    p = head;
    while(p) {
        if (p->random) {
            p->next->random = p->random->next;
        }
        p = p->next->next;
    }

    p = head, q = dummy;
    while(p) {
        q->next = p->next;
        p->next = p->next->next;
        p = p->next;
        q = q->next;
    }
    return dummy->next;
}

