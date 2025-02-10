
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};
    vector<string> res;
    int i = 0, start = i;
    while(i < n) {
        start = i;
        while (i < n-1 && nums[i] + 1 == nums[i+1]) i++;
        string interval = to_string(nums[start]);
        if (start < i) interval.append("->" + to_string(nums[i]));
        res.push_back(interval);
        i++;
    }
    return res;
}

vector<string> summaryRanges1(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};
    vector<string> res;
    string interval = "";
    interval.append(to_string(nums[0]));
    int i = 1;

    for (i = 1; i < n; i++) {
        if (nums[i-1] + 1 != nums[i]) { 
            string pre = to_string(nums[i-1]);
            if (interval != pre) interval += ("->" + to_string(nums[i-1]));
            res.push_back(interval);
            interval = to_string(nums[i]);
        }
    }

    string pre = to_string(nums[i-1]);
    if (interval != pre) interval += ("->" + to_string(nums[i-1]));
    res.push_back(interval);

    return res;
}

int main () {
    vector<int> nums1 = {0, 1, 2, 4, 5, 7};
    for (auto range: summaryRanges(nums1)) {
        cout << range << endl;
    }
}