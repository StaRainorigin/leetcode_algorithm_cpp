#include <vector>
#include <iostream>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int i = 0, j = 0, possess = 0;
    while (i < n && j < n) {
        possess += (gas[(i+j)%n] - cost[(i+j)%n]) ;
        if (possess < 0) {
            i += (j+1);
            j = 0;
            possess = 0;
        } else {
            j++;
        }
    }
    return (j==n) ? i : -1;
}
// int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//     int n = gas.size(), sum = 0, index=-1;
//     vector<int> subs(n, 0);
//     vector<int> res(n, 0);
//     for (int i=0; i<n; i++) {
//         subs[i] = gas[i] - cost[i];
//         sum += subs[i];
//     }
//     if(sum < 0) return index;
//     for (int i=0; i<n; i++) {
//         res[i] = sum-subs[i];
//     }
//     for (int i=0; i<n; i++) {
//         if (index>=0 && res[i]>=0) return -1;
//         else if (index<0 && res[i]>=0) index = i;
//         cout << "ban" << endl;
//     }
//     return index;
// }

int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int res = canCompleteCircuit(gas, cost);
    cout << res << endl;
}