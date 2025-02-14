
#include <vector>
using namespace std;

#include <cstddef>
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 解法 1
vector<Node*> pre;
void dfs(Node* node, int depth) {
    if (!node) return;
    if (depth == pre.size()) {
        pre.push_back(node);
    } else {
        pre[depth]->next = node;
        pre[depth] = node;
    }
    dfs(node->left, depth+1);
    dfs(node->right, depth+1);
}

Node* connect1(Node* root) {
    dfs(root, 0);
    return root;
}


// 解法 2
vector<Node*> queue;
Node* connect2(Node* root) {
    if (!root) return nullptr;
    queue.push_back(root);
    while(!queue.empty()) {
        vector<Node*> nxt;
        for (int i = 0; i < queue.size(); i++) {
            Node* node = queue[i];
            if (i) queue[i-1]->next = node;
            if (node->left) nxt.push_back(node->left);
            if (node->right) nxt.push_back(node->right);
        }
        queue = std::move(nxt);
    }
    return root;
}

// 解法 3
Node* connect3(Node* root) {
    Node dummy;
    Node* cur = root;
    while(cur) {
        dummy.next = nullptr;
        Node* nxt = &dummy;
        while(cur) {
            if (cur->left) {
                nxt->next = cur->left;
                nxt = cur->left;
            }
            if (cur->right) {
                nxt->next = cur->right;
                nxt = cur->right;
            }
            cur = cur->next;
        }
        cur = dummy.next;
    }
    return root;
}