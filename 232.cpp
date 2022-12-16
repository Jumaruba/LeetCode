class MyQueue {
public:
    stack<int> aux; 
    stack<int> inv; 
    MyQueue() {
        aux = stack<int>();
        inv = stack<int>();
    }
    
    void push(int x) {
        while(!inv.empty()){
            aux.push(inv.top());
            inv.pop();
        }
        aux.push(x); 
        while(!aux.empty()){
            inv.push(aux.top());
            aux.pop();
        }
    }
    
    int pop() {
        int v = inv.top();
        inv.pop();
        return v;
    }
    
    int peek() {
        return inv.top();
    }
    
    bool empty() {
        return inv.empty();
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
