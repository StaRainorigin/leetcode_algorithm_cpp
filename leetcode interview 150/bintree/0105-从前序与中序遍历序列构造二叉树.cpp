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

TreeNode* build (vector<int>& preorder, unordered_map<int, int>& inorder_map,
                int left, int right, int& preorder_index) {
    if (left == right) return nullptr;

    int root_val = preorder[preorder_index++];
    TreeNode* root = new TreeNode(root_val);

    int mid = inorder_map[root_val];
    root->left = build(preorder, inorder_map, left, mid, preorder_index);
    root->right = build(preorder, inorder_map, mid + 1, right, preorder_index);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorder_map;
    for (int i = 0; i < inorder.size(); i++) {
        inorder_map[inorder[i]] = i;
    }
    int preorder_index = 0;
    return build (preorder, inorder_map, 0, inorder.size(), preorder_index);
}

