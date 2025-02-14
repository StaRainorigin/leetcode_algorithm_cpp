struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int count = 0;
void countInner(TreeNode* root) {
    if (!root) return;
    count++;
    countInner(root->left);
    countInner(root->right);
}

int countNodes1(TreeNode* root) {
    countInner(root);
    return count;
}