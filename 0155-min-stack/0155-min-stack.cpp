class MinStack {
     stack<long long>st;
    long long minm;
public:
    // stack<long long>st;
    // long long minm;
    MinStack() {
    }
    
    void push(int val) {
        long long a=val;
        if(st.empty()){
            st.push(a);
            minm=a;
        }
        else{
           if(val<minm){
               st.push(2*a*1LL-minm);
               minm=a;
           }
            else
                st.push(a);
        }
    }
    
    void pop() {
        if(st.top()>minm)
             st.pop();
        else{
          minm=2*minm- st.top();
            st.pop();
        }
    }
    
    int top() {
        long long a=st.top();
        // st.pop();
        if(a<minm)
            return minm;
        return a;
    }
    
    int getMin() {
        return minm;
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