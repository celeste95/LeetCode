int mySqrt(int x) {
    int i=1;
    if(x==0) return 0;
    if(x>=2147395600) return 46340;
    while(i*i<=x) i++;
    return i-1;
}

//binary search


int mySqrt(int x) 
{
	if ( x <= 1 )
		return x;
	
    int begin = 1;
    int end = x;

    while( begin <= end )
    {
    	int middle = begin + (end - begin)/2 ;
    	if ( middle == x / middle )
    	{
    		return middle;
    	}
    	else if( middle < x / middle )
    	{
    		begin = middle + 1;
    	}
    	else
    	{
    		end = middle - 1;
    	}
    }

    return end;
}