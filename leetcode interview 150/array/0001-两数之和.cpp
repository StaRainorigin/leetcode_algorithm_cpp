#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) { 
    int n = nums.size();
    unordered_map<int, int> idx;
    for (int i=0; ; i++) {
        auto it = idx.find(target-nums[i]);
        if (it != idx.end()) {
            return {it->second, i};
        }
        idx[nums[i]] = i;
    }
}

int main () {
    
}