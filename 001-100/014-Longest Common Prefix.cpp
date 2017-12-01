class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        if(strs.size()==0) return s;
        char cur;
        for(int i=0;i<strs[0].length();i++)
        {
            cur=strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j][i]!=cur) return s;
            }
            s+=cur;
        }
        return s;
    }
};