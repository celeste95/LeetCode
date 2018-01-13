class Solution {
private:
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> part;
        dfs(part,s,4);
        return res;
    }
    void dfs(vector<string>& part, string s, int left)
    {
        if(left==0&&s.length()==0) {
            res.push_back(part[0]+"."+part[1]+"."+part[2]+"."+part[3]);
            return;
        }
        if(s.length()>left*3) return;
        if(s.length()<left) return;
        part.push_back(s.substr(0,1));
        dfs(part,s.substr(1),left-1);
        part.pop_back();
        if(s.length()<2) return;
        if(s[0]=='0') return;
        part.push_back(s.substr(0,2));
        dfs(part,s.substr(2),left-1);
        part.pop_back();
        if(s.length()<3||stoi(s.substr(0,3))>255) return;
        part.push_back(s.substr(0,3));
        dfs(part,s.substr(3),left-1);
        part.pop_back();
        return;
    }
};