#include <iostream>
#include <vector>
using namespace std;
bool canJump(vector<int>& nums) {

    // vector<bool> can_arrive;
    // for (int i=0; i<nums.size()-1; i++) can_arrive.push_back(false);
    // can_arrive.push_back(true);

    // for (int i=nums.size()-1; i>=0; i--) {
    //     for (int j=1; j<=nums[i] && i+j<nums.size(); j++) {
    //         if(can_arrive[i+j]) {
    //             can_arrive[i] = true;
    //             break;
    //         }
    //     }
    // }
                                                                               
    // return can_arrive[0];

    int n = nums.size();
    int reach = 0;
    for (int i=0; i<n && i<=reach; i++) {
        reach = max(reach, i+nums[i]);
        if (reach >= n-1) {
            return true;
        }
    }
    return false;
}



int main() {
    vector<int> nums = {3, 2, 1, 0, 4, 5, 6, 0};
    bool res = canJump(nums);
    cout << res << endl;
}