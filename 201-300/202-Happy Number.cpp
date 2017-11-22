class Solution {
public:
    vector<int> history;
    bool isHappy(int n) {
        int sum=0;
        while(n)
        {
            sum+=((n%10)*(n%10));
            n/=10;
        }
        if(sum==1) return true;
        if(history.end()!=find(history.begin(),history.end(),sum)) return false;
        else 
        {
            history.push_back(sum);
            return isHappy(sum);
        }
    }
};