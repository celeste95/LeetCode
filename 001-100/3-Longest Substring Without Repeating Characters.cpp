class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		//AC 35ms
        int app[255]={0};
        int len = 0;
        int max = 0;
        for(int i=0;i<s.length();i++)
        {
            if(!app[s[i]])
            {
                len++;
                app[s[i]]=1;
                if(len>max) max=len;
            }
            else
            {
                int j;
                len=0;
                memset(app,0,255*sizeof(int));
                for(j=i-1;j>=0;j--)
                {
                    if(s[j]==s[i]) break;
                    len++;
                    app[s[j]]=1;
                }
                len++;
                app[s[i]]=1;
                if(len>max) max=len;
            }
        }
        return max;
    }
	
	
	int lengthOfLongestSubstring(string s) {
		//example
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};