bool isValid(char* s) {
    int idx=0,i;
    char* stack;
    stack = malloc(9999*sizeof(char));
    stack[idx]='b';
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
        {
            idx++;
            stack[idx]=s[i];
        }
        if(s[i]==')')
        {
            if(stack[idx]!='(') return false;
            else idx--;
        }
        if(s[i]==']')
        {
            if(stack[idx]!='[') return false;
            else idx--;
        }
        if(s[i]=='}')
        {
            if(stack[idx]!='{') return false;
            else idx--;
        }
    }
    if(idx==0) return true;
    else return false;
}