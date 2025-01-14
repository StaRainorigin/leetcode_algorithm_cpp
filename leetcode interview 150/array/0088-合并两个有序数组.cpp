#include "vector"
#include <cstdio>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1, j=n-1, k=m+n-1;
    while(i>=0 && j>=0) nums1[k--] = nums1[i]>nums2[j] ? nums1[i--] : nums2[j--];
    while(i>=0) nums1[k--] = nums1[i--];
    while(j>=0) nums1[k--] = nums2[j--];

}

int main() {
    // vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    // vector<int> nums2 = {2, 5, 6};
    // merge(nums1, 3, nums2, 3);
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    merge(nums1, 0, nums2, 1);

}