class MinStack {
public:
    stack<long long> st;
    long long minVal = INT_MAX;

    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            minVal = value;
        } 
        else if (value >= minVal) {
            st.push(value);
        } 
        else {
            st.push((long long)2 * value - minVal);
            minVal = value;
        }
    }
    void pop() {
        if (st.top() < minVal) {
             minVal = ((long long)2*minVal - st.top());
        }
        st.pop();
    }
    int top() { 
        if(st.top() < minVal){
            return minVal;
        }

        return st.top();
     }

    int getMin() {
         return minVal;
        }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */