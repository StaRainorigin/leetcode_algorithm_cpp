#include <iostream>
#include <string>
using namespace std;
class Solution {
private:
    string R[4][10] = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, // 个位
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, // 十位
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, // 百位
        {"", "M", "MM", "MMM"}, // 千位
    };

public:
    string intToRoman(int num) {
        return R[3][num / 1000] + R[2][num / 100 % 10] + R[1][num / 10 % 10] + R[0][num % 10];
    }
};


int main () {
    Solution *st = new Solution();
    cout << st->intToRoman(3749) << endl;
}


// #define M 1000
// #define CM 900
// #define D 500
// #define CD 400
// #define C 100
// #define XC 90
// #define L 50
// #define XL 40
// #define X 10
// #define IX 9
// #define V 5
// #define IV 4
// #define I 1

// string intToRoman(int num) {
//     string s = "";
//     while(num > 0) {
//         if (num >= M) {
//             s.append("M");
//             num -= M;
//         } else if (num >= CM) {
//             s.append("CM");
//             num -= CM;
//         } else if (num >= D) {
//             s.append("D");
//             num -= D;
//         } else if (num >= CD) {
//             s.append("CD");
//             num -= CD;
//         } else if (num >= C) {
//             s.append("C");
//             num -= C;
//         } else if (num >= XC) {
//             s.append("XC");
//             num -= XC;
//         } else if (num >= L) {
//             s.append("L");
//             num -= L;
//         } else if (num >= XL) {
//             s.append("XL");
//             num -= XL;
//         } else if (num >= X) {
//             s.append("X");
//             num -= X;
//         } else if (num >= IX) {
//             s.append("IX");
//             num -= IX;
//         } else if (num >= V) {
//             s.append("V");
//             num -= V;
//         } else if (num >= IV) {
//             s.append("IV");
//             num -= IV;
//         } else if (num >= I) {
//             s.append("I");
//             num -= I;
//         }
//     }
//     return s;
// }


// int main () {
//     cout << intToRoman(3749) << endl;
// }

