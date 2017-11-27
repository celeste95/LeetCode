class MyQueue {
public:
    stack<int> s;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        int idx=0;
        vector<int> temp;
        while(!s.empty())
        {
            temp.push_back(s.top());
            s.pop();
        }
        s.push(x);
        for(int i=1;i<=temp.size();i++)
        {
            s.push(temp[temp.size()-i]);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp=s.top();
        s.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        return s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};


class MyQueue {
	//example
public:
/* Idea:
 *   1. push elements to stack input as usual;
 *   2. when pop() and peek() needed, reverse the order in stack input by moving them to stack output;
 *   3. As all elements are moved like step 2 once after pushing to stack input, amotized time complexity is O(1)
 */
    /** Initialize your data structure here. */
    stack<int> input, output;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        reverse();
        int res = output.top();
        output.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        reverse();
        return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
    
    void reverse() {
        if(output.empty()) {
            while(input.size()) {
                output.push(input.top());
                input.pop();
            }
        }
    }
        
};




