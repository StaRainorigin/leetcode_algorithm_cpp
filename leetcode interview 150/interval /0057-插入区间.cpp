
#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if(intervals.empty()) return {newInterval};
    int n = intervals.size();
    vector<vector<int>> res;
    int i = 0;
    bool flag = true;
    while(i < n) {
        vector<int> interval = intervals[i];
        if(flag) {
            if ((newInterval[0] <= interval[0] && newInterval[1] >= interval[0]) || (newInterval[0] > interval[0] && newInterval[0] <= interval[1])) {
                interval[0] = min(interval[0], newInterval[0]);
                interval[1] = max(interval[1], newInterval[1]);
                while(i < n-1 && interval[1] >= intervals[i+1][0]) {
                    interval[1] = max(interval[1], intervals[i+1][1]);
                    i++;
                }
                flag = false;
            } else if (newInterval[1] < interval[0]) {
                res.push_back(newInterval);
                flag = false;
            }
        }
        res.push_back(interval);
        i++;
    }
    if (flag) {
        res.push_back(newInterval);
    }
    return res;
}

int main() {
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    insert(intervals1, newInterval1);
}