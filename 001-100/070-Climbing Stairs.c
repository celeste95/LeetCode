int a[9999]={0};

int climbStairs(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
    if(a[n]) return a[n];
    else
    {
        a[n]=climbStairs(n-1)+climbStairs(n-2);
        return a[n];
    }
}

//best solution in C 
//递推


int climbStairs(int n) {
   /*
   这个版本会超时
    if(n <= 2)
        return n;
    else
        return climbStairs(n - 2) + climbStairs(n - 1);
    */
    
    if(n <= 2)
        return n;
    int l = 1, h = 2, i = 0;
    int sum = 0;
    for(i = 3; i <= n; i ++)
    {
        sum = l + h;
        l = h;
        h = sum;
    }
    return h;
}