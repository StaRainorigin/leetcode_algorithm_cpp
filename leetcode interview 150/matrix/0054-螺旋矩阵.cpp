#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return {};
    int top = 0, left = 0, right = matrix[0].size() - 1, bottom = n - 1;
    vector<int> ans;
    while(top <= bottom && left <= right) {
        // for (int i=0; i<top; i++) ans.push_back(matrix[top])
    }
    

}


int main () {

}