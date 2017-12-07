class Solution {
public:
    string intToRoman(int num) {
        int temp;
        string ret;
        int base[8]={5000,1000,500,100,50,10,5,1};
        char sym[8]={'A','M','D','C','L','X','V','I'};
        for(int i=1;i<8;i++)
        {
            while(num/base[i])
            {
                if(i%2==0)
                {
                    if(num/base[i+1]==9)
                    {
                        ret.push_back(sym[i+1]);
                        ret.push_back(sym[i-1]);
                        num=num%base[i+1];
                        i++;
                        break;
                    }
                }
                temp=num/base[i];
                num=num%base[i];
                if(temp==4)
                {
                    ret.push_back(sym[i]);
                    ret.push_back(sym[i-1]);
                }
                else
                {
                    while(temp--) ret.push_back(sym[i]);
                }
            }
        }
        return ret;
    }
};