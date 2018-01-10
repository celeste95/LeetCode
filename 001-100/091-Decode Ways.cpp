class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0||s[0]=='0') return 0;
        if(s.length()==1 && s[0]=='0') return 0;
        vector<int> ways(s.length()+1);
        ways[0]=1;ways[1]=1;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='0'&&(s[i-1]=='0'||s[i-1]>'2')) return 0;
            if(s[i]=='0'&&(s[i-1]-'0')<3&&(s[i-1]-'0')>0)
            {
                ways[i+1]=ways[i-1];
                continue;
            }
            if(s[i-1]=='0') {ways[i+1]=ways[i];continue;}
            if((s[i]-'0'+10*(s[i-1]-'0'))>26) ways[i+1]=ways[i];
            else ways[i+1]=ways[i]+ways[i-1];
        }
        return ways[s.length()];
    }
};




 int n = s.size();
    if(n == 0 || s[0] == '0') return 0;
    if(n == 1) return 1;
    int res = 0,fn_1 = 1,fn_2 = 1;
    for(int i = 1;i < n;i++){
        int temp = fn_1;
        if(isValid(s[i])&&isValid(s[i-1],s[i]))  res+=fn_1+fn_2;
        if(!isValid(s[i])&&isValid(s[i-1],s[i])) res+=fn_2;
        if(isValid(s[i])&&!isValid(s[i-1],s[i])) res+=fn_1;
        if(!isValid(s[i])&&!isValid(s[i-1],s[i]))  return 0;
        fn_1 = res;
        fn_2 = temp;
        res = 0;
    }
    return fn_1;
}
bool isValid(char a,char b){
    return a == '1'||(a == '2' && b <='6');
}
bool isValid(char a){
    return a != '0';
}