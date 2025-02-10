#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 不用找出满足条件的数列，所以不要用找数列的方式思考这个问题
int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;  // 处理空输入

    unordered_map<int, int> idx;
    int max_length = 0;

    for (int num : nums) {
        if (idx.count(num)) continue;  // 避免重复处理相同数字

        int left = idx.count(num - 1) ? idx[num - 1] : 0;   // 不会新增
        int right = idx.count(num + 1) ? idx[num + 1] : 0;
        // int left = idx[num-1], right = idx[num+1];
        int temp = left + right + 1;

        max_length = max(max_length, temp);

        idx[num] = temp;
        idx[num - left] = temp;  // 更新区间起始点
        idx[num + right] = temp; // 更新区间结束点
    }

    return max_length;
}

int main () {
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums1) << endl;
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums2) << endl;
}