#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> miniSt;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(miniSt.empty() || value <= miniSt.top())
            miniSt.push(value);
    }
    
    void pop() {
        if(!st.empty()) {
            if(st.top() == miniSt.top())
                miniSt.pop();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return miniSt.top();
    }
};

int main(void) {

    return 0;
}