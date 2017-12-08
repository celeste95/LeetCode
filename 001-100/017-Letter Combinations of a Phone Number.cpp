class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector <string>> alph;
        alph.push_back({"a","b","c"});
        alph.push_back({"d","e","f"});
        alph.push_back({"g","h","i"});
        alph.push_back({"j","k","l"});
        alph.push_back({"m","n","o"});
        alph.push_back({"p","q","r","s"});
        alph.push_back({"t","u","v"});
        alph.push_back({"w","x","y","z"});
        vector<string> ret;
        if(digits.length()==0) return ret;
        queue<string> q;
        for(int i=0;i<alph[digits[0]-'2'].size();i++)
        {
            q.push(alph[digits[0]-'2'][i]);
        }
        for(int i=1;i<digits.length();i++)
        {
            int size=q.size();
            for(int j=0;j<size;j++)
            {
                string temp=q.front();
                q.pop();
                for(int k=0;k<alph[digits[i]-'2'].size();k++)
                {
                    q.push(temp+alph[digits[i]-'2'][k]);
                }
            }
        }
        while(!q.empty())
        {
            ret.push_back(q.front());
            q.pop();
        }
            
        return ret;
    }
};