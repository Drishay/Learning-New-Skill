class MyQueue {
public:
    MyQueue() {  
    }
    stack <int> s1;
    stack <int> s2;

    void push(int x) {
        if(s1.empty()){
            s1.push(x);
            return;
        }

        int s1_size = s1.size();
        for(int i = 1; i<=s1_size; i++){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        for(int i = 1; i<=s1_size; i++){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
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