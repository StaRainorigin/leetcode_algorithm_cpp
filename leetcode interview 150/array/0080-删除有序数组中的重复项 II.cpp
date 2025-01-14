#include <cstdio>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int fast=0, slow=0, count=0;
    while(fast<nums.size()) {
        if(nums[fast]==nums[slow]) {
            if(count<2) count++;
            fast++;
        } else {
            if (count==1) {
                nums[slow+1] = nums[fast];
            } else {
                nums[slow+1] = nums[slow];
                nums[slow+2] = nums[fast];
            }
            slow+=count;
            count=0;
        }
        if(count==2) nums[slow+1] = nums[slow];
    }
    return slow+count;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int res = removeDuplicates(nums);
    printf("%d\n", res);
}