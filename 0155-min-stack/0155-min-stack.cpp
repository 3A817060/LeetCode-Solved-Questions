class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        data.push(val);
        if(min_stack.empty()||val<=min_stack.top())
            min_stack.push(val);
    }
    
    void pop() {
        if(data.top() == min_stack.top())
            min_stack.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
    
private: 
    stack<int> data, min_stack;
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */