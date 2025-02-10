#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size(), ans = 0, left = 0;
    unordered_set<char> window;
    for (int right = 0; right < n; right ++) {
        char c = s[right];
        while(window.find(c) != window.end()) {
            window.erase(s[left++]);
        }
        window.insert(c);
        ans = max(ans, right - left + 1);
    }
    return ans;

}

int lengthOfLongestSubstring1(string s) {
    int n = s.size();
    if (n == 0) return 0;

    unordered_map<int, int> idx;
    int count = 0, left = 0;

    for (int right = 0; right < n; right++) {
        if (idx.find(s[right]) != idx.end() && idx[s[right]] >= left) {
            left = idx[s[right]] + 1;
        }
        
        idx[s[right]] = right;
        count = max(count, right - left + 1);
    }

    return count;
}

// int lengthOfLongestSubstring(string s) {
//     int n = s.size();
//     if (n == 0) return 0;
//     unordered_map<int, int> idx;
//     int count = 0, i = 0, j = 0;
//     while (i + j < n) {
//         if (idx.find(s[i + j]) == idx.end()) {
//             idx[s[i + j]] = i + j;
//             j++;
//         } else {
//             i = i + j;
//             count = max(count, j );
//             j = 0;
//             idx.clear();
//         }
//     }
//     i = i + j;
//     count = max(count, j );
//     return count;
// }

int main() {
    string s1 = "abcabcbb";
    cout << lengthOfLongestSubstring(s1) << endl;
    string s2 = "bbbbb";
    cout << lengthOfLongestSubstring(s2) << endl;
    string s3 = "pwwkew";
    cout << lengthOfLongestSubstring(s3) << endl;
    string s4 = " ";
    cout << lengthOfLongestSubstring(s4) << endl;

}