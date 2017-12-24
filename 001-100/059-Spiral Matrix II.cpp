class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n,vector<int>(n,0));
        int num=0;
        for(int i=0;i<(n+1)/2;i++)
        {
            int j,k,l,m;
            for(j=i;j<n-i-1;j++) ret[i][j]=++num;
            for(k=i;k<n-i-1;k++) ret[k][j]=++num;
            for(l=n-i-1;l>i;l--) ret[k][l]=++num;
            for(m=n-i-1;m>i;m--) ret[m][l]=++num;
        }
        if(n%2) ret[n/2][n/2]=++num;
        return ret;
    }
};
