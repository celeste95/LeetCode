class Solution {
public:
    bool isIsomorphic(string s, string t) {
		//TLE
        int i,j;
        for(i=0;i<s.length();i++)
        {
            for(j=i+1;j<t.length();j++)
            {
                if(s[i]==s[j]&&t[i]!=t[j]) return false;
                if(s[i]!=s[j]&&t[i]==t[j]) return false;
            }
        }
        return true;
    }
};



class Solution {
public:
    bool isIsomorphic(string s, string t) {
		//AC my solution
        int a[255][255]={0};
        vector<bool> exist_s(255,false);
        vector<bool> exist_t(255,false);
        for(int i=0;i<s.length();i++)
        {
            if(exist_s[s[i]]||exist_t[t[i]])
            {
                if(!a[s[i]][t[i]]) return false;
            }
            else
            {
                exist_s[s[i]]=true;
                exist_t[t[i]]=true;
                a[s[i]][t[i]]=1;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		//example solution 空间复杂度更低
        if (s.size() != t.size()) return false;
        char st[256] = {0}, ts[256] = {0};
        for (int i=0; i<s.size(); i++) {
            if (st[t[i]] != ts[s[i]]) return false;
            st[t[i]] = i+1;
            ts[s[i]] = i+1;
        }
        return true;
    }
};