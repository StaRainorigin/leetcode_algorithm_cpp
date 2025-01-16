#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 计算模式串的 nextval 数组
void computeNextVal(const string& pattern, vector<int>& nextval) {
    int m = pattern.length();
    nextval[0] = -1;  // nextval[0] 定义为 -1
    int j = -1;  // j 是模式串的前缀后缀匹配的指针

    for (int i = 1; i < m; ++i) {
        // 遇到不匹配时，回退 j
        while (j >= 0 && pattern[j + 1] != pattern[i]) {
            j = nextval[j];  // 回退到 nextval[j] 的位置
        }

        // 如果匹配，则继续扩展 j
        if (pattern[j + 1] == pattern[i]) {
            j++;
        }

        // 将当前的 j 存入 nextval[i]
        nextval[i] = (pattern[i] == pattern[j]) ? j : -1;
    }
}



int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    if (m==0) return 0;

    vector<int> nextval(m, 0);
    computeNextVal(needle, nextval);
    int i=0, j=0;
    while(i < n) {
        if(haystack[i] == needle[j]) {
            i++;
            j++;
            if (j == m) {
                return i-j;
            }
        } else {
            if (j > 0) {
                j = nextval[j-1] + 1;
            } else {
                i++;
            }
        }
    }
    return -1;
}

int main () {
    string haystack = "sadbutsad", needle = "sad";
    cout << strStr(haystack, needle) << endl;
}