#include "vector"
#include <cstdio>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    // int len = nums.size();
    // if (len>1) {
    //     int i=0, j=1;
    //     while(j<len) {
    //         while(j<len && nums[i]==nums[j]) j++;
    //         nums[++i] = nums[j++]; 
    //     }
    //     return i+1;
    // }
    // return 1;
    int j=0;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i]!=nums[j]) {
            nums[++j] = nums[i];
        }
    }
    return j+1;
}

int main() {
    // vector<int> nums = {1, 1, 2};
    // vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums = {1, 1};
    printf("%d\n",removeDuplicates(nums));
}

