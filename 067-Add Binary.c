char* addBinary(char* a, char* b) {
    int i;
    int la;
    int lb;
    char *sum,*temp;
    int *carry;
    if(strlen(a)<strlen(b))
    {
        temp=a;
        a=b;
        b=temp;
    }
    la=strlen(a);
    lb=strlen(b);
    sum = (char*)malloc((strlen(a)+2)*sizeof(char));
    carry = (int*)malloc((strlen(a)+1)*sizeof(int));
    carry[0]=0;
    sum[la+1]='\0';
    for(i=1;i<=lb;i++)
    {
        if(a[la-i]=='0')
        {
            if(b[lb-i]=='0')
            {
                if(carry[i-1]==0)
                {//000
                    sum[la+1-i]='0';
                    carry[i]=0;
                }
                else
                {//001
                    sum[la+1-i]='1';
                    carry[i]=0;
                }
            }
            else
            {
                if(carry[i-1]==0)
                {//010
                    sum[la+1-i]='1';
                    carry[i]=0;
                }
                else
                {//011
                    sum[la+1-i]='0';
                    carry[i]=1;
                }
            }
        }
        else
        {
            if(b[lb-i]=='0')
            {
                if(carry[i-1]==0)
                {//100
                    sum[la+1-i]='1';
                    carry[i]=0;
                }
                else
                {//101
                    sum[la+1-i]='0';
                    carry[i]=1;
                }
            }
            else
            {
                if(carry[i-1]==0)
                {//110
                    sum[la+1-i]='0';
                    carry[i]=1;
                }
                else
                {//111
                    sum[la+1-i]='1';
                    carry[i]=1;
                }
            }
        }
    }
    for(;i<=la;i++)
    {
        if(a[la-i]=='0')
        {
            if(carry[i-1]==0)
            {
                sum[la+1-i]='0';
                carry[i]=0;
            }
            else
            {
                sum[la+1-i]='1';
                carry[i]=0;
            }
        }
        else
        {
            if(carry[i-1]==0)
            {
                sum[la+1-i]='1';
                carry[i]=0;
            }
            else
            {
                sum[la+1-i]='0';
                carry[i]=1;
            }
        }
    }
    if(carry[i-1]==1) sum[0]='1';
    else sum[0]='0';
    while(*sum=='0'&&*(sum+1)!='\0') sum++;
    return sum;
}