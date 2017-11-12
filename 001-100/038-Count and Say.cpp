class Solution {
public:
    string countAndSay(int n)
    {
        if(n==1) return "1";
        else
        {
            string last=countAndSay(n-1);
            char pre=last[0];
            char* now=(char*)malloc(2*last.length()*sizeof(char)+1);
            now[0]='1';
            now[1]=pre;
            int idx=0;
            for(int i=1;i<last.length();i++)
            {
                if(last[i]==pre) now[idx]++;
                else
                {
                    idx+=2;
                    now[idx]='1';
                    now[idx+1]=last[i];
                    pre=last[i];
                }
            }
            now[idx+2]='\0';
            return now;
        }
    }
};
