#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// 题目说的是大于等于

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int i = 0, j = 0, count = INT_MAX, sum = 0;
    while (j < n) {
        sum += nums[j];
        while(sum >= target) {
            count = min(count, j - i + 1);
            sum -= nums[i++];
        }
        j++;
    }
    return count == INT_MAX ? 0 : count;
}

int main () {
    vector<int> nums = {2,3,1,2,4,3};
    int res = minSubArrayLen(7, nums);
    cout << res << endl;
}