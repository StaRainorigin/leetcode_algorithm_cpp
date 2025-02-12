
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root) {
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        if (root->left) invertTree(root->left);
        if (root->right) invertTree(root->right);
        return root;
    } else {
        return nullptr;
    }
}
