#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int max_capacity = 0, left = 0, right = n-1;
    while(left < right) {
        max_capacity = max(max_capacity, min(height[left], height[right])*(right-left));
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_capacity;
}

int main () {
    vector<int> height1 = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height1) << endl;
}