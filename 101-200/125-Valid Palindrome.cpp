class Solution {
public:
    bool isPalindrome(string s) {
		//my solution
        string temp="";
        int i=0;
        for(i=0;i<s.length();i++)
        {
            if(s[i]<='9'&&s[i]>='0') temp.push_back(s[i]);
            if(s[i]<='z'&&s[i]>='a') temp.push_back(s[i]);
            if(s[i]<='Z'&&s[i]>='A') temp.push_back(s[i]-'A'+'a');
        }
        for(i=0;i<temp.length()/2;i++)
        {
            if(temp[i]!=temp[temp.length()-i-1]) return false;
        }
        return true;
    }
};


bool isPalindrome(string s) {
	//brief example
	int start=0, end=s.length()-1;
	while(start<end) {
		if (!isalnum(s[start])) start++;
		else if (!isalnum(s[end])) end--;
		else {
			if (tolower(s[start++])!=tolower(s[end--])) return false;
		}
	}
	return true;
}