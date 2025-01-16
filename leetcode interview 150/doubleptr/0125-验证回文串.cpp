#include <cctype>
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    bool is_palindrome = true;
    int n = s.size();
    int left = 0, right = n-1;
    while(left < right) {
        if (!isalpha(s[left]) && !isdigit(s[left])) {
            left++;
        } else if(!isalpha(s[right]) && !isdigit(s[right])) {
            right--;
        } else if(tolower(s[left]) != tolower(s[right])) {
            is_palindrome = false;
            break;
        } else {
            left++;
            right--;
        }
    }
    return is_palindrome;
}

int main () {
    string s = "0P";
    cout << isPalindrome(s) << endl;
}