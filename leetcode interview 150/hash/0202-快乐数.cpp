#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> getNum(int n) {
    int num = n;
    vector<int> res;
    while(num != 0) {
        res.push_back(num % 10);
        num /= 10;
    }
    return res;
}

bool isHappy (int n) {
    int num = n;
    bool flag = true;
    unordered_map<int, int> idx;
    while(num != 1) {
        vector<int> split_nums = getNum(num);
        num = 0;
        for (int split_num: split_nums) {
            num += split_num * split_num;
        }
        if (idx[num] != 0) {
            flag = false;
            break;
        } else {
            idx[num] = 1;
        }
    }
    return flag;
}

int main () {
    cout << isHappy(19) << endl;
}