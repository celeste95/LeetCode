class Solution {
public:
    int titleToNumber(string s) {
        int i=0,sum=0;
        while(i<s.length())
        {
            sum=sum*26+(s.at(i)-'A'+1);
            i++;
        }
        return sum;
    }
};