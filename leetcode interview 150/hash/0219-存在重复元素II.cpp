#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0, j = 0;
    unordered_set<int> sets;
    while (i < n) {
        if (i > k) sets.erase(nums[j++]);
        if (sets.count(nums[i]) == 1) {
            return true;
        } else {
            sets.insert(nums[i]);
        }
        i++;
    }
    return false;
}

int main () {
    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    cout << containsNearbyDuplicate(nums1, k1) << endl;

    vector<int> nums2 = {1, 2, 3, 4, 1};
    int k2 = 3;
    cout << containsNearbyDuplicate(nums2, k2) << endl;
}