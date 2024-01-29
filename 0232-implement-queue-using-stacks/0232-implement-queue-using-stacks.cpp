class MyQueue {
public:
 stack<int>s1;
  stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int res=0;
        if(!s2.empty()){
          res= s2.top();
          s2.pop();
          return res;
        }
         while(!s1.empty()){
           s2.push(s1.top());
           s1.pop();
         }
         res=s2.top();
         s2.pop();
         return res;
           
    }
    
    int peek() {
         int res=0;
        if(!s2.empty()){
          res= s2.top();
          return res;
        }
         while(!s1.empty()){
           s2.push(s1.top());
           s1.pop();
         }
         res=s2.top();
         return res; 
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */