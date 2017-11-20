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
	

    int trailingZeroes(int n) {
        int result=0;
        while(n>0){
            result=result+n/5;
            n=n/5;
        }
        return result;
        
    }
};