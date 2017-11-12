char* longestCommonPrefix(char** strs, int strsSize) 
{
    int i=0; int j=0;int index;int tempindex=0;
    if(strsSize<1)
    return "";
    index=strlen(strs[0]);
    char *a;
    a= malloc(sizeof(char)*(index+1));
    strcpy(a,strs[0]);
    for(i=1;i<strsSize;i++)
    {   tempindex=0;
        for(j=0;j<index;j++)
        { 
            if(a[j]==strs[i][j])
            tempindex++;
            else
            {a[j]='\0';
             break;
            }
        } 
          if (tempindex==0)return ("");
          if(tempindex<index)index=tempindex;
        
    }
    return a;
    
}