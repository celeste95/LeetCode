int romanToInt(char* s) {
    int i,num=0,len=0;
    int arr[20]={0};
    len=strlen(s);
    for(i=len-1;i>=0;i--)
    {
        switch(s[i])
        {
            case 'I': 
                arr[i]=1;
                break;
            case 'V': 
                arr[i]=5;
                break;
            case 'X': 
                arr[i]=10;
                break;
            case 'L': 
                arr[i]=50;
                break;
            case 'C': 
                arr[i]=100;
                break;
            case 'D': 
                arr[i]=500;
                break;
            case 'M': 
                arr[i]=1000;
                break;
        }
        if(arr[i]<arr[i+1]) num-=arr[i];
        else num+=arr[i];
    }
    return num;
}