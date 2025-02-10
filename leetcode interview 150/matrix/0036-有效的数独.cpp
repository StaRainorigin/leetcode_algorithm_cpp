#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<char> row, s1, s2, s3;
    vector<unordered_set<char>*> grids = {&s1, &s2, &s3};  // 使用指针避免拷贝
    for (int i = 0; i < 9; i++) {
        row.clear();
        if (i % 3 == 0) {
            for (auto grid : grids) grid->clear();  // 使用指针来清空原始集合
        }
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c != '.') {
                if (row.find(c) != row.end() || grids[j / 3]->find(c) != grids[j / 3]->end()) {
                    return false;
                }
                row.insert(c);
                grids[j / 3]->insert(c);  // 使用指针访问原集合
            }
        }
    }
    return true;

}

int main () {

}