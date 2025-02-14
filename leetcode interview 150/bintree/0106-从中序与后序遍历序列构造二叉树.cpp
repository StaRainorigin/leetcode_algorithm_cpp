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

TreeNode* build(unordered_map<int, int>& inorder_map, int left, int right, vector<int>& postorder, int& index) {
    if (left >= right || index < 0) return nullptr; // 增加 index 的边界检查
    int root_val = postorder[index--]; // 先使用 index，再递减
    int mid = inorder_map[root_val]; // 获取根节点在 inorder 中的索引
    // 先构建右子树，再构建左子树（因为 postorder 是左右根的顺序）
    TreeNode* right_child = build(inorder_map, mid + 1, right, postorder, index);
    TreeNode* left_child = build(inorder_map, left, mid, postorder, index);
    return new TreeNode(root_val, left_child, right_child);
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inorder_map;
    for (int i = 0; i < inorder.size(); i++) {
        inorder_map[inorder[i]] = i;
    }
    int index = postorder.size() - 1; // 从最后一个元素开始
    return build(inorder_map, 0, inorder.size(), postorder, index);
}