class Solution {
public:
    void reverseWords(string &s) {
        int index=0;
        while(s[0]==' ') s.erase(s.begin());
        reverse(s.begin(), s.end());
        index=0;
        while(index<s.size()) {
            while(s[index]==' ') s.erase(s.begin()+index);
            int start=index;
            while(s[index]!=' '&&index<s.size()) index++;
            int end=index;
            reverse(s.begin()+start,s.begin()+end);
            index++;
        }
    }
};