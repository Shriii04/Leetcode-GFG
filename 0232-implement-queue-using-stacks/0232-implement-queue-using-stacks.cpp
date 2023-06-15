
class MyQueue {
    // Define the data members(if any) here.
    stack<int> s1,s2;
    public:
    MyQueue() {
        // Initialize your data structure here.
    }

    void push(int x) {
        // Implement the enqueue() function.
        s1.push(x);
    }

    int pop() {
        // Implement the dequeue() function.
        if(s1.empty() && s2.empty()){
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int front = s2.top();
        s2.pop();
        return front;
    }

    int peek() {
        // Implement the peek() function here.
        if(s1.empty() && s2.empty()){
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        // Implement the isEmpty() function here.
        if(s1.empty() && s2.empty()){
            return 1;
        }
        return 0;
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