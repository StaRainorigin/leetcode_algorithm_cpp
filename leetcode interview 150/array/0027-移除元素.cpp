#include <cstdio>
#include <vector>
using namespace std;

// int removeElement(vector<int>& nums, int val) {
//     int n = nums.size()-1;
//     if(n>=0) {
//         while(nums[n]==val) n--;
//         for(int i=0; i<n; i++) {
//             if(nums[i]==val) {
//                 int temp = nums[i];
//                 nums[i] = nums[n];
//                 nums[n] = temp;
//                 while(nums[n]==val) n--;
//             }
//         }
//     }
//     return n+1;
// }

// int removeElement(vector<int>& nums, int val) {
//     int k=0;
//     for (int i=0; i<nums.size(); i++) {
//         if(nums[i] != val) {
//             nums[k++] = nums[i];
//         }
//     }
//     return k;
// }


int removeElement(vector<int>& nums, int val) {
    int k=0;
    for (int num : nums) if (num != val) nums[k++] = num;
    return k;
}


int main() {
    // vector<int> nums = {3, 2, 2, 3};
    vector<int> nums = {1};
    printf("%d", removeElement(nums, 1));

}