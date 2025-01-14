#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int ans = 0, left = 0, right = height.size()-1, pre_max = 0, suf_max = 0;
    while(left < right) {
        pre_max = max(pre_max, height[left]);
        suf_max = max(suf_max, height[right]);
        ans += pre_max < suf_max ? pre_max - height[left++] : suf_max - height[right--];
    }
    return ans;
}



int trap1(vector<int>& height) {
    int n = height.size(), water = 0;
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    for (int i=1; i<n; i++) {
        left[i] = left[i-1] > height[i-1] ? left[i-1] : height[i-1];
        right[n-i-1] = right[n-i] > height[n-i] ? right[n-i] : height[n-i];
    }
    for (int i=0; i<n; i++) {
        int w = min(left[i], right[i]) - height[i];
        if (w>0) {
            water += w;
        }
    }
    return water;
}

int main () {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = trap(height);
    cout << res << endl;
}