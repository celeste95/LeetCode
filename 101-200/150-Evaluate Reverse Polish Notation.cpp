class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int a,b,c;
        for(int i=0;i<tokens.size();i++) {
            if(tokens[i]=="+") {
                a=nums.top();
                nums.pop();
                b=nums.top();
                nums.pop();
                c=b+a;
                nums.push(c);
                continue;
            }
            if(tokens[i]=="-") {
                a=nums.top();
                nums.pop();
                b=nums.top();
                nums.pop();
                c=b-a;
                nums.push(c);
                continue;
            }
            if(tokens[i]=="*") {
                a=nums.top();
                nums.pop();
                b=nums.top();
                nums.pop();
                c=b*a;
                nums.push(c);
                continue;
            }
            if(tokens[i]=="/") {
                a=nums.top();
                nums.pop();
                b=nums.top();
                nums.pop();
                c=b/a;
                nums.push(c);
                continue;
            }
            //a=atoi(tokens[i]);
            nums.push(atoi(tokens[i].c_str()));
        }
        return nums.top();
    }
};