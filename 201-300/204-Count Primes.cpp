class Solution {
	//TLE
public:
    int countPrimes(int n) {
        vector<int> cnt(n+1);
        cnt[0]=0;
        for(int i=1;i<=n;i++)
            cnt[i]=cnt[i-1]+(IsPrime(i-1)?1:0);
        return cnt[n];
    }
    bool IsPrime(int number)
    {
        if(number==0||number==1) return false;
        int i;
        for (i=2; i<=sqrt(number); i++) if (number % i == 0) return false;
        return true;	
    }

};

class Solution {
	//AC
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 0; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;
                }    
            }    
        }
        return count(prime.begin(), prime.end(), true);
    }
};