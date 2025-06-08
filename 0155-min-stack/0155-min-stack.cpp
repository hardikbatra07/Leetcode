class MinStack {
    stack<int> s;
    multiset<int> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        st.insert(val);
    }
    
    void pop() {
        auto it=st.find(s.top());
        st.erase(it);
        s.pop();
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return *st.begin();
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