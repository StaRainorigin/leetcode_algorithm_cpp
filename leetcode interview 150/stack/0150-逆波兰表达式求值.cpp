#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    int num1, num2, res;
    for (auto &token: tokens) {

        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%") {
            num1 = st.top();
            st.pop();
            num2 = st.top();
            st.pop();
            switch (token[0]) {
                case '+': {
                    res = num2 + num1;
                    break;
                }
                case '-': {
                    res = num2 - num1;
                    break;
                }
                case '*': {
                    res = num2 * num1;
                    break;
                }
                case '/': {
                    res = num2 / num1;
                    break;
                }
                case '%': {
                    res = num2 % num1;
                }
            }
            st.push(res);
        } else {
            istringstream ss(token);
            ss >> num1;
            st.push(num1);
        }
    }

    return st.top();
}

int main () {
    vector<string> tokens1 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evalRPN(tokens1) << endl;
    vector<string> tokens2  {"4","13","5","/","+"};
    cout << evalRPN(tokens2) << endl;
}