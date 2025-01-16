#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n == 0) return 0;
    unordered_map<int, int> idx;
    int count = 0, i = 0, j = 0;
    while (i + j < n) {
        if (idx.find(s[i + j]) == idx.end()) {
            idx[s[i + j]] = i + j;
            j++;
        } else {
            i = idx[i + j] + 1;
            count = max(count, j );
            j = 0;
            idx.clear();
        }
    }
    i = i + j;
    count = max(count, j );
    return count;
}

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