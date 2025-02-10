#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    int n = s.size(), m = t.size();
    if (n != m) return false;
    bool flag = true;
    unordered_map<char, int> maps1;
    unordered_map<char, int> maps2;
    for (int i = 0; i < n; i++) {
        maps1[s[i]]++;
        maps2[t[i]]++;
    }
    for (int i = 0; i < maps1.size(); i++) {
        if (maps1[i] != maps2[i]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    string s1 = "anagram", t1 = "nagaram";
    cout << isAnagram(s1, t1) << endl;
    string s2 = "rat", t2 = "car";
    cout << isAnagram(s2, t2) << endl;
}