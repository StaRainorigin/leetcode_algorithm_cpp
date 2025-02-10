#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string minWindow(string s, string t) {
    int n = s.size(), m = t.size();
    if (n < m) return "";

    unordered_map<char, int> counts;
    int left = 0, right = 0;
    for (int i = 0; i < m; i++) {
        counts[t[i]] = 0;
    }
    for (int i = 0; i < n; i++) {
        if(counts.find(s[i]) != counts.end()) {
            right = i;
            char c = s[right];
            counts[c]++;
            if (s[left] == c) {
                while(1) {
                    auto it = counts.find(s[left]);
                    if (it != counts.end() && it->second > 1) {
                        counts[s[left++]]--;
                    } else if (it != counts.end()) {
                        break;
                    } else {
                        left++;
                    }
                }
            }
        }
        while(left < right && counts.find(s[left]) == counts.end()) left++;
    }

    for (int i = 0; i < m; i++) {
        if (counts[t[i]] == 0) return "";
    }

    string ans = "";
    for (int i = left; i <= right; i++) {
        ans.append({s[i]});
    }
    return ans;
}

int main () {
    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << "\"" << minWindow(s1, t1) << "\"" << endl;
}