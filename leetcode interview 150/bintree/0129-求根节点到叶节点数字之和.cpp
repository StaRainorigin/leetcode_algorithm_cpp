struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sumInner(TreeNode* root, int high) {
    if (!root) return 0;
    int num = high * 10 + root->val;
    if (root->left || root->right) {
        return sumInner(root->left, num) + sumInner(root->right, num);
    } else {
        return num;
    }
}

int sumNumbers(TreeNode* root) {
    return sumInner(root, 0);     
}