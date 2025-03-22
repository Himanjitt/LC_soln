class MyStack {
public:
    int arr[100];
    int t = -1;
    MyStack() {}

    void push(int x) {
        t += 1;
        arr[t] = x;
    }

    int pop() {
        int ans = arr[t];
        t -= 1;
        return ans;
    }

    int top() { return arr[t]; }

    bool empty() {
        if (t == -1) {
            return true;
        }

        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */