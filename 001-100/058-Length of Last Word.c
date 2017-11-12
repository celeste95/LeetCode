int lengthOfLastWord(char* s) {
    int sum=0;
    int i;
    if(strlen(s)==0) return 0;
    i=strlen(s)-1;
    while(s[i]==' '&&i>=0) i--;
    if(i<0) return 0;
    for(;s[i]!=' '&&i>=0;i--)
    {
        sum++;
    }
    return sum;
}