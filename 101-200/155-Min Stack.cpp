class MinStack {
public:
    /** initialize your data structure here. */
    vector <int> s;
    //int stacktop=0;
    int min = INT_MAX;
    MinStack() {
    }
    
    void push(int x) {
        s.push_back(x);
        //stacktop++;
        if(x<min) min=x;
    }
    
    void pop() {
        if(s.size()==0) return;
        if(top()!=min) s.pop_back();
        else
        {
            s.pop_back();
            int temp=INT_MAX;
            for(int i=0;i<s.size();i++)
            {
                if (s[i]<temp) temp=s[i];
            }
            min = temp;
        }
    }
    
    int top() {
        return s[s.size()-1];
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
 
class MinStack {
	//23ms
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || s2.top() >= x) {
            s2.push(x);
        }
    }
    
    void pop() {
        if (s1.empty()) {
            return;
        }
        int t = s1.top();
        s1.pop();
        if (!s2.empty() && t == s2.top()) {
            s2.pop();
        }
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1, s2;
};
