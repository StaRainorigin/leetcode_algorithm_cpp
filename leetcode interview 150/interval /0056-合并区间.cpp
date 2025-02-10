#include <algorithm>

#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n == 0) return {};
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    vector<vector<int>> res;
    int i = 0;
    while (i < n) {
        vector<int> interval = intervals[i];
        while (i < n-1 && interval[1] >= intervals[i+1][0]) {
            interval[1] = max(interval[1], intervals[i+1][1]);
            i++;
        }
        res.push_back(interval);
        i++;
    }
    return res;
}

int main () {
    vector<vector<int>> intervals = {{2, 3}, {4, 5}, {6, 7}, {8 ,9}, {1, 10}};
    merge(intervals);
}