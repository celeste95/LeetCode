class Solution {
public:
    int uniquePaths(int m, int n) {
        long long int ret=1;
        m--;
        n--;
        for(int i=max(m,n)+1;i<=m+n;i++) ret*=i;
        for(int i=min(m,n);i>0;i--) ret/=i;
        return (int)ret;
    }
};