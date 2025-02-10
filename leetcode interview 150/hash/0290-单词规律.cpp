#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> split (string str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);

    while(getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}



bool wordPattern(string pattern, string s) {
    vector<string> ss = split(s, ' ');
    int n = pattern.size(), m = ss.size();
    if (n != m) return false;
    bool flag = true;
    unordered_map<char, int> maps1;
    unordered_map<string, int> maps2;
    for(int i = 0; i < n; i++) {
        if(maps1[pattern[i]] != maps2[ss[i]]) {
            flag = false;
            break;
        }
        maps1[pattern[i]] = i + 1;
        maps2[ss[i]] = i + 1;
    }
    return flag;
}

int main () {
    string  pattern = "abba", s = "dog cat cat dog";
    cout << wordPattern(pattern, s) << endl;    
}