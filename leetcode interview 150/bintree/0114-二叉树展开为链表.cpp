#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverse(TreeNode* root, queue<TreeNode*>& q) {
    q.push(root);
    if(root->left) traverse(root->left, q);
    if(root->right) traverse(root->right, q);
}

void flatten(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    traverse(root, q);
    TreeNode* node = q.front();
    q.pop();
    while(!q.empty()) {
        node->right = q.front();
        node = node->right;
        q.pop();
    }
}