#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int n = ransomNote.size(), m = magazine.size();
    bool flag = true;
    unordered_map<char, int> maps;
    for (int i = 0; i < m; i++) {
        maps[magazine[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (--maps[ransomNote[i]] < 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main () {
    string ransomNote1 = "aa", magazine1 = "aab";
    cout << canConstruct(ransomNote1, magazine1) << endl;
}