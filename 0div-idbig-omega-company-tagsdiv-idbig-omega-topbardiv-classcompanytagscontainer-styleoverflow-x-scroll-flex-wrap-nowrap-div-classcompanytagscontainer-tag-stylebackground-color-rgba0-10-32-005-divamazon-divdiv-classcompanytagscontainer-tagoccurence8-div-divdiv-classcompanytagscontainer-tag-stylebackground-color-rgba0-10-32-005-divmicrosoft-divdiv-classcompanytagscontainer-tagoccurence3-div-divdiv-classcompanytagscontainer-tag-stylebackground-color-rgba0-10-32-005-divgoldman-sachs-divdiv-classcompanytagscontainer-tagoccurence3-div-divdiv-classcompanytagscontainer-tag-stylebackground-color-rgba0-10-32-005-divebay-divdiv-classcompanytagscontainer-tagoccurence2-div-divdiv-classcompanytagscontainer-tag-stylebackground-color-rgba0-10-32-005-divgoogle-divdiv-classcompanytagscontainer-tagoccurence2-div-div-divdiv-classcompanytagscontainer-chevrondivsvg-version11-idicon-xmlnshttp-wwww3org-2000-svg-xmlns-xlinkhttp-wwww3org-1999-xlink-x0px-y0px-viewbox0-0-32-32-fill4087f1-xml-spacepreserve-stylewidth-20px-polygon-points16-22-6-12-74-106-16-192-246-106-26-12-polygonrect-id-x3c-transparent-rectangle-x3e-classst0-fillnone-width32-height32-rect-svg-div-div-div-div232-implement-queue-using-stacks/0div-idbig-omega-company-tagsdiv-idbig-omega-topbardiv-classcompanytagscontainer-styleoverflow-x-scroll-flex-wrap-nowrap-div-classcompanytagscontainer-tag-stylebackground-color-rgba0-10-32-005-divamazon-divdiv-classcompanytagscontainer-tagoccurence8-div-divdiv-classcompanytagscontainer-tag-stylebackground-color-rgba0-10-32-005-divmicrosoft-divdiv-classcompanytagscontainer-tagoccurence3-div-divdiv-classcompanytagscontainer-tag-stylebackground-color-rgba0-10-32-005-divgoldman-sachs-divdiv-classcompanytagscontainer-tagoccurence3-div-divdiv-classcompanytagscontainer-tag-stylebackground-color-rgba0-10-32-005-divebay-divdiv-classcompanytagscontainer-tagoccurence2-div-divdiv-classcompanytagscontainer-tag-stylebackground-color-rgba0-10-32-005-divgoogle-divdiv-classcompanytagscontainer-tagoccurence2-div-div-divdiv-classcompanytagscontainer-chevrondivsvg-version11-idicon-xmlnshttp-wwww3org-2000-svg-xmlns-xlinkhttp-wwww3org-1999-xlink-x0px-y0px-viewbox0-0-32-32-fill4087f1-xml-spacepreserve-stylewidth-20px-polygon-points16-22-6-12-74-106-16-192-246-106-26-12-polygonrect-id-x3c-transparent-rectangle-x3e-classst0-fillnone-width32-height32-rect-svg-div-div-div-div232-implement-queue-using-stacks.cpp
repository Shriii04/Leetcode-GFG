class MyQueue {
public:
    stack<int> s1,s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
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