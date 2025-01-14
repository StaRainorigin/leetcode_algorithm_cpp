#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (k>n) k %= n;
    reverse(nums.begin(), nums.begin()+n-k);
    reverse(nums.begin()+n-k, nums.begin()+n);
    reverse(nums.begin(), nums.begin()+n);
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> nums2 = {-1, -100, 3, 99};
    rotate(nums1, 3);
    rotate(nums2, 2);
    for (int num: nums1) cout << num << " ";
    cout << endl;
    for (int num: nums2) cout << num << " ";
    cout << endl;
}