#include <iostream>
#include <string>
using namespace std;

// 最后一个一般可以变成从后往前

int lengthOfLastWord(string s) {
    int n = s.size(), count = 0;
    for (int i=n-1; i>=0; i--) {
        if (count > 0 && s[i] == ' ') break;
        else if(s[i] != ' ') count ++;
    }
    return count;
}
// int lengthOfLastWord(string s) {
//     int n = s.size();
//     // int res = 0, count = 0, index = 0;
//     int res = 0, count = 0;
//     for (int i=0; i<n; i++) {
//         if (s[i] == ' ') {
//             // if (i!=index+1) res = count;
//             // if (count > 0) res = count;
//             res = (count>0) ? count : res;
//             count = 0;
//             // index = i;
//         } else {
//             count ++;
//             res = count;
//         }
//     }
//     return res;
// }

int main () {
    string s1 = "Hello World";
    cout << lengthOfLastWord(s1) << endl;
    string s2 = "   fly me   to   the moon  ";
    cout << lengthOfLastWord(s2) << endl;
    string s3 = "luffy is still joyboy";
    cout << lengthOfLastWord(s3) << endl;
}