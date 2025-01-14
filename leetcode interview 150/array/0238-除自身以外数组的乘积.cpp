#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size(), sum = 1;
    vector<int> res(n, 0);
    res[0] = 1;
    for (int i=1; i<n; i++) {
        res[i] = res[i-1] * nums[i-1];
    }
    for (int i=n-2; i>=0; i--) {
        sum *= nums[i+1];
        res[i] *= sum;
    }
    return  res;
}


vector<int> productExceptSelf1(vector<int>& nums) {
    int n = nums.size();
    vector<int> L(n, 0), R(n,0);
    L[0] = 1;
    R[n-1] = 1;

    int sum = 1;
    for (int i=1; i<n; i++) {
        sum *= nums[i-1];
        L[i] = sum;
    }

    sum = 1;
    for (int i=n-2; i>=0; i--) {
        sum *= nums[i+1];
        R[i] = sum;
    }

    for (int i=0; i<n; i++) {
        L[i] *= R[i]; 
    }
    return L;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = productExceptSelf(nums);
    for (int re: res) {
        cout << re << endl;
    }
}