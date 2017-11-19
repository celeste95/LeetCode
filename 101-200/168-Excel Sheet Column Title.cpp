class Solution {
public:
    string convertToTitle(int n) {
		//my solution 3ms
        if(n<=0) return NULL;
        string ret;
        if(n<27) 
        {
            //string ret;
            ret.push_back('A'+n-1);
        }
        else 
        {
            //string ret;
            ret=convertToTitle((n-1)/26);
            if(n%26==0)ret.push_back('Z');
            else ret.push_back('A'+n%26-1);
        }
        return ret;
    }
	
	
	string convertToTitle(int n) {
		//example solution 0ms
        return (n==0) ? "" : convertToTitle( (n-1)/26 ) + char( (n-1)%26 +'A' );
    }
};