#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams1(vector<string>& strs) {
    vector<string> temp = strs;
    vector<vector<string>> res;
    unordered_map<string, int> maps;
    int index = 0;
    int n = strs.size();
    for (int i = 0; i < n; i++) {
        sort(temp[i].begin(), temp[i].end());
        if (maps.count(temp[i]) == 0) {
            maps[temp[i]] = index++;
            res.push_back({strs[i]});
        } else {
            res[maps[temp[i]]].push_back(strs[i]);
        }
    }    
   return res;
}

vector<vector<string>> groupAnagrams2(vector<string>& strs) {
    vector<vector<string>> res;
    // unordered_map<unordered_map<char, int>, int> maps;
    return res;
}

int main () {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for (auto res: groupAnagrams1(strs)) {
        for (auto re: res) {
            cout << re << " ";
        }
        cout << endl;
    }
}