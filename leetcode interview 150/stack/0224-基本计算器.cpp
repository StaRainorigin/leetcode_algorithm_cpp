#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int calculate(string s) {
    int n = s.size();
    stack<int> st;
    st.push(1);
    int sign = 1;
    int i = 0;
    int ans = 0;
    while(i < n) {
        if (s[i] == ' ') {
            i++;
        } else if (s[i] == '+') {
            sign = st.top();
            i++;
        } else if (s[i] == '-') {
            sign = -st.top();
            i++;
        } else if (s[i] == '(') {
            st.push(sign);
            i++;
        } else if (s[i] == ')') {
            st.pop();
            i++;
        } else {
            long num = 0;
            while(i < n && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                i++;
            }
            ans += sign * num;
        }
    }
    return ans;
}

int main () {

}
