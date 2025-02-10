#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    unordered_map<char, char> brackets = {{')', '('}, {'}', '{'}, {']', '['}};
    if (s.size() % 2 == 1) return false;
    stack<char> st;
    bool ans = true;
    for (auto c: s) {
        if (brackets.count(c) == 0) {
            st.push(c);
        } else if (st.empty() || brackets[c] != st.top()) {
            ans = false;
            break;
        } else {
            st.pop();
        }
    }
    return st.empty() ? ans: false;
}

int main () {
    string s = "([])";
    cout << isValid(s) << endl;
}