#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size(), candy = 2;
    vector<int> candies(n, 1);
    for (int i=0; i<n-1; i++) {
        if (ratings[i] < ratings[i+1]) {
            candies[i+1] = max(candies[i+1], candy);
            candy ++;
        } else {
            candy = 2;
        }
    }
    candy = 2;
    for (int i=n-1; i>0; i--) {
        if (ratings[i] < ratings[i-1]) {
            candies[i-1] = max(candies[i-1], candy);
            candy++;
        } else {
            candy = 2;
        }
    }
    candy = 0;
    for (int i=0; i<n; i++) candy += candies[i];
    return candy;
}

int main() {
    vector<int> candies = {1, 3, 4, 5, 2};
    int res = candy(candies);
    cout << res << endl;
}