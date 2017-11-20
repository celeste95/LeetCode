class Solution {
public:
    int trailingZeroes(int n) {
		//Time limit exceeded
        int num=0;
        int temp,sum;
        for(int i=5;i<=n;i+=5)
        {
            temp=i;
            sum=0;
            while(temp%5==0)
            {
                sum++;
                temp/=5;
            }
            num+=sum;
        }
        return num;
    }
	
	int trailingZeroes(int n) 
	{
	    int result = 0;
	    for(long long i=5; n/i>0; i*=5){
	        result += (n/i);
	    }
	    return result;
	}
};