#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 数组中有h个不小于h的值，求最大的h

int hIndex2(vector<int>& citations) {
    int n = citations.size(), tot = 0;
    vector<int> counter(n + 1);
    
    for (int i = 0; i < n; i++) {
        if (citations[i] >= n) {
            counter[n]++;
        } else {
            counter[citations[i]]++;
        }
    }

    for (int i = n; i >= 0; i--) {
        tot += counter[i];
        if (tot >= i) {
            return i;
        }
    }
    return 0;
}

int hIndex1(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int n = citations.size();
    for (int i=0; i<n; i++) {
        if (i >= citations[n-1-i]) return n-1-i;
    }
    return 0;
}

int main() {
    // vector<int> citations = {3, 0, 6, 1, 5};
    // vector<int> citations = {0, 1};
    vector<int> citations = {11, 15};
    int res = hIndex1(citations);
    cout << res << endl;
}