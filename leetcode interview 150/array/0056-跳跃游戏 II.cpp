#include <iostream>
#include <vector>
using namespace std;

// 默认能够到达

int jump(vector<int>& nums) {
    // 什麽时候计步数? i到达边界时, 为0时计数. 对于n-1, 由于n-1不会到达, 所以不需要考虑到n-1还会多计一步的问题
    // 对于不可到达的数组? 没有做任何处理
    // 是否可以提前退出? 好像没有
    int n = nums.size();
    int max_index = 0, count = 0, border = 0;
    for (int i=0; i<n-1; i++) {
        max_index = max(max_index, i+nums[i]);
        if (i==border) {
            border = max_index;
            count ++;
        }
    }
    return count;
}


int jumpbackup2(vector<int>& nums) {
    int n = nums.size();
    int count = 1, max_index = 0,  border = nums[0];
    for (int i=1; i<n; i++) {
        if (i>border) { //这里有问题, 还有第二个问题, 应该和下面 求max_index 交换
            border = nums[max_index];
            count ++;
        }
        max_index = nums[i]+i>nums[max_index]+max_index ? i : max_index;
        if (nums[max_index] >= n-1) return count;
        // if (nums[max] == border && nums[max] == 0) return 0;        
    }
    return count;
}


int jumpbackup(vector<int>& nums) {
    int n = nums.size();
    int i = 0, count = 0;
    while (i < n-1) {
        int max_index = i+1;
        for (int j=i+2; j<=i+nums[i] && j<n; j++) {
            if (nums[j]+j >= n-1 || (nums[j]+j > nums[max_index]+max_index )) {
                max_index = j;
            }
        }
        if(nums[max_index] == 0) {
            return 0;
        } else {
            i = max_index;
            count ++;
        }
    }
    return count;
}

int main() {
    // vector<int> nums = {3, 2, 1, 6, 0, 5, 2};
    // vector<int> nums = {2, 1};
    // vector<int> nums = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
    vector<int> nums = {3, 2, 1, 0, 4};
    int res = jump(nums);
    cout << res << endl;

}

// 3 3 3 9 4 10 
// 3 2 1 6 0 5 2
// 3 2 1 1 4
// 3 2 1 0 4
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11]
// [5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0]
// [5,10, 5, 5, 5, 5, 8,10,11,10,10,11]