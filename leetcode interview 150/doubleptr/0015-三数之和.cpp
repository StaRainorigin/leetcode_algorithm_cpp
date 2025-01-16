#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 确定时间复杂度不能优化到 O(n), 那么就尽情的排序吧!

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());  // 排序，避免重复三元组

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;  // 跳过重复元素
        }

        int left = i + 1, right = n - 1;  // 双指针
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});
                // 跳过重复的元素
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < 0) {
                left++;  // 需要更大的值
            } else {
                right--;  // 需要更小的值
            }
        }
    }

    return res;


}

int main () {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(nums);
    for (vector<int> r1: res) {
        for (int r2: r1) {
            cout << r2 << " ";
        }
        cout << endl;
    } 
}