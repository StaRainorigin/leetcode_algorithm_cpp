#include <climits>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string> 
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    size_t min_len = INT_MAX, n = strs.size();
    string s = "";
    for (int i=0; i<strs.size(); i++) min_len = min(min_len, strs[i].size());
    for (int i=0; i<min_len; i++) {
        char c = strs[0][i];
        for (int j=1; j<n; j++) if (c != strs[j][i]) return s;
        s.append(string(1, c));
    }
    return s;
}

int main () {
    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs) << endl;
}