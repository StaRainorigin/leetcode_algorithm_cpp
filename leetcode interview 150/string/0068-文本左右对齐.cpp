#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    
}

int main () {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> res = fullJustify(words, 16);
    for (string s: res) {
        cout << "\"" << s << "\""<< endl;
    }
}