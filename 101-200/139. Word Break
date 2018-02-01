class Solution {
    //TLE
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length()<=0) return true;
        for(int i = 1; i<=s.length(); i++) {
            if(find(wordDict.begin(),wordDict.end(),s.substr(0,i))!=wordDict.end())
                //return true;
                if(wordBreak(s.substr(i),wordDict)) return true;
        }
        return false;
    }
};

class Solution {
    //DP AC
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> res(s.length()+1);
        res[0]=true;
        for(int i=1; i <= s.length(); i++){
            for(int j=0; j < i; j++){
                if(res[j] && find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                    res[i] = true;
                    break;
                }
            }
        }
        return res[s.length()];
    }
};
