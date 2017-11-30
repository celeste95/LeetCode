class Solution {
public:
    bool isAnagram(string s, string t) {
		//AC 23ms
        if(s.length()!=t.length()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=t[i]) return false;
        }
        return true;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
		//AC 6ms
        if (s.length() != t.length()) {
            return false;
        }
        int m[256] = {0};
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
            m[t[i]]--;
        }
        for (int x : m) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
};