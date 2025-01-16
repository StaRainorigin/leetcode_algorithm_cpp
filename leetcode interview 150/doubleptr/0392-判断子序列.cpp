#include <iostream>
#include <string>
using namespace std;

bool isSubsequence (string s, string t) {
    if (s.empty()) return true;
    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    bool is_subsequence = false;
    while (i < n && m - j >= n - i) {
        if (s[i] == t[j] && i==n-1) {
            is_subsequence = true;
            break;
        } else if(s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return is_subsequence;
}

int main () {
    string s1 = "abc", t1 = "ahbgdc";
    cout << isSubsequence(s1, t1) << endl;
    string s2 = "axc", t2 = "ahbgdc";
    cout << isSubsequence(s2, t2) << endl;
}