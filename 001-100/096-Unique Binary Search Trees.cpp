class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n+1,1);
        for(int i=2;i<=n;i++)
        {
            int sum=0;
            for(int j=0;j<i;j++) sum+=res[j]*res[i-j-1];
            res[i]=sum;
        }
        return res[n];
    }
};