#include <iostream>
#include <string>

using namespace std;
    

int romanToInt(string s) {
    int n = s.size(), ans = 0;
    for (int i=0; i<n; i++) {
        switch (s[i]) {
            case 'I': 
                ans += 1;
                break;
            case 'V': 
                ans += (i!=0 && s[i-1]=='I') ? 3 : 5;
                break;
            case 'X':
                ans += (i!=0 && s[i-1]=='I') ? 8 : 10;
                break;
            case 'L':
                ans += (i!=0 && s[i-1]=='X') ? 30 : 50;
                break;
            case 'C':
                ans += (i!=0 && s[i-1]=='X') ? 80 : 100;
                break;
            case 'D':
                ans += (i!=0 && s[i-1]=='C') ? 300 : 500;
                break;
            case 'M':
                ans += (i!=0 && s[i-1]=='C') ? 800 : 1000;
                break;
        }
    }
    return ans;
}

int main () {
    string s1 = "LVIII";
    cout << romanToInt(s1) << endl;
    string s2 = "MCMXCIV";
    cout << romanToInt(s2) << endl;

}