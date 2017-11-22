class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num=0;
        for(int i=0;i<32;i++)
        {
            if(n%2) num++;
            n/=2;
        }
        return num;
    }
};