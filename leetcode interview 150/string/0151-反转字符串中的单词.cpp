#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverseWords3(string s) { 
    int left = 0, right = s.size()-1;
    while (s[left] == ' ') left++;
    while (s[right] == ' ') right--;
    return s;
}



string reverseWords2(string s) {
    int n = s.size(), right = n;
    string ans = "";;

    // 从字符串的末尾遍历
    for (int i = n - 1; i >= -1; --i) {
        if (i == -1 || s[i] == ' ') {
            // 如果有单词，添加该单词到答案中
            if (i + 1 != right) {
                ans.append(s.substr(i + 1, right - i - 1));
                ans.append(" "); // 添加一个空格
            }
            right = i; // 更新右边界
        }
    }
    while (ans.back() == ' ') ans.pop_back();
    
    return ans;
}

string reverseWords1(string s) {
    int n = s.size();
    string ans = "";
    vector<string>stack = {};

    for (char c: s) {
        if (c == ' ' && ans != "") {
            stack.push_back(ans);
            ans = "";
        } else if (c != ' ') {
            ans.append({c});
        }
    }
    if (s[n-1] != ' ' && ans != "") stack.push_back(ans);
    ans = "";
    for (int i=stack.size()-1; i>=0; i--) {
        ans.append(stack[i]);
        ans.append(" ");
    }
    if (!ans.empty()) ans.pop_back();
    return ans;
}

int main (){
    // string s1 ="the sky is blue";
    // cout << reverseWords2(s1) << endl;
    string s2 = "  hello world  ";
    cout << "\"" << reverseWords2(s2) << "\"" << endl;
}