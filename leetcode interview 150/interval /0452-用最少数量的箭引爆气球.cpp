#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    int n = points.size(), i = 0, count = 0;
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    while(i < n) {
        int right = points[i][1];
        while(i < n-1 && right >= points[i+1][0]) i++;
        i++;
        count++;
    }
    return count;
}

int main () {
    vector<vector<int>> points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << findMinArrowShots(points1) << endl;
}