#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int min_price = INT_MAX, max_profit = 0;
    for(int i=0; i<prices.size(); i++) {
        if(prices[i]<min_price) {
            min_price = prices[i];
        } else {
            max_profit = prices[i]-min_price>max_profit? prices[i]-min_price : max_profit;
        }
    }
    return max_profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int res = maxProfit(prices);
    cout << res << endl;
}