struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool travese(TreeNode* root, int targetSum, int sum) {
    if (!root) return false;
    int new_sum = sum + root->val;
    if (!root->left && !root->right) return targetSum == new_sum;
    return travese(root->left, targetSum, new_sum) || travese(root->right, targetSum, new_sum);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    return travese(root, targetSum, 0);
}