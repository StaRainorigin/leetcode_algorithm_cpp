#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

string simplifyPath(string path) {
    if (path.empty()) return "/";
    int n = path.size();
    vector<string> stack;
    string str = "", ans = "";
    istringstream ss(path);
    while(getline(ss, str, '/')){
        if (str.empty() || str == ".") {
            continue;
        } else if (str != "..") {
            stack.push_back(str);
        } else if (!stack.empty()) {
            stack.pop_back();
        }
    }
    for (auto s: stack) {
        ans.append("/");
        ans.append(s);
    }
    return stack.empty() ? "/" : ans;
}

int main () {
    string path1 = "/.../a/../b/c/../d/./";
    cout << simplifyPath(path1) << endl;
}