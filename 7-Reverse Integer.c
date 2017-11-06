int reverse(int x) {
    int flag=0;
    long long y=0;
    if(x<0) 
    {
        flag = 1;
        x = 0 - x;
    }
    while(1)
    {
        y=10*y+x%10;
        if( (x/10) ==0 ) break;
        x=x/10;
    }
    if(flag) y=0-y;
    if(y>2147483647||y<-2147483648) return 0;
    return (int)y;
}