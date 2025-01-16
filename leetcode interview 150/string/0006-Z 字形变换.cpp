#include <cmath>
#include <iostream>
#include <string>
using namespace std;

string convert(string s, int numRows) {
    int n = s.size();
    string ans = "";
    for (int i=0; i<numRows; i++) {
        bool flag = i>0 && i<numRows-1;
        for(int j=i; j<n; j+=max(1, 2*(numRows-1))) {
            ans.append({s[j]});
            if (flag) {// 非顶非底, 欲添加元素在边界内, 则加一下后面那个元素, 前面的元素和行数有关
                int next = j+2*(numRows-1-i);
                if (next<n) ans.append({s[next]});
            }
        }
    }
    return ans;
}

int main() {
    string s = "0123456789";
    cout << convert(s, 4) << endl;
}
// 0 1 2 3 4 5 6 7 8 9 10

// 1
// 0 1 2 3 4 5

// 2
// 0 2 4 6 8 
// 1 3 5 7 9

// 3
// 0   4   8 
// 1 3 5 7 9 
// 2   6

// 4
// 0     6 
// 1   5 7 
// 2 4   8 
// 3     9

// 5
// 0       8
// 1     7 9
// 2   6  10
// 3 5    11
// 4      12

// 6          
// 0        10
// 1       911
// 2     8  12
// 3   7    13
// 4 6      14
// 5        15

// P A Y P A L I S H I R I N G 
// 4           
// P        I        N
// A     L  S     I  G
// Y  A     H  R  
// P        I  