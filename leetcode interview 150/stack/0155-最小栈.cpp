#include <algorithm>
#include <climits>

#include <stack>
using namespace std;
/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(val);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/
class MinStack {
private:
    stack<int> mins;
    stack<int> st;
public:
    MinStack() {
        mins.push(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        mins.push(min(mins.top(), val));
    }
    
    void pop() {
        st.pop();
        mins.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
