#include "iostream"
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count++;
        } else {
            count += (candidate != num) ? 1 : -1;
        }
    }
    return candidate;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int res = majorityElement(nums);
    cout << res << endl;
}