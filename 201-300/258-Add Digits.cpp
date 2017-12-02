class Solution {
public:
    int addDigits(int num) {
        if(num%10==num) return num;
        else 
        {
            int sum=0;
            while(num)
            {
                sum+=num%10;
                num/=10;
            }
            return addDigits(sum);
        }
    }
};

class Solution {
public:
    int addDigits(int num) {
		//digit root
        return 1 + (num - 1) % 9;
    }
};