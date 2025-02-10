#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;
    int n = s.size();
    bool flag = true;
    unordered_map<char, int> maps1, maps2;
    for (int i = 0; i < n; i++) {
        int i_s = maps1[s[i]], i_t = maps2[t[i]];
        if (i_s != i_t) {
            flag = false;
            break;
        }
        maps1[s[i]] = i+1;
        maps2[t[i]] = i+1;
    }
    return flag;
}

int main () {
    string s = "aa", t = "ab";
    cout << isIsomorphic(s, t) << endl;
}