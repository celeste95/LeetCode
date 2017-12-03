// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
		//TLE
        int left=1,right=n,mid=(left+right)/2;
        while(!(isBadVersion(mid)&&!isBadVersion(mid-1))&& left<right)
        {
            if(isBadVersion(mid))
            {
                right=mid-1;
                mid=(left+right)/2;
            }
            else
            {
                left=mid+1;
                mid=(left+right)/2;
            }
        }
        return mid;
    }
};


int firstBadVersion(int n) {
	//AC
    int lower = 1, upper = n, mid;
    while(lower < upper) {
        mid = lower + (upper - lower) / 2;
        if(!isBadVersion(mid)) lower = mid + 1;   /* Only one call to API */
        else upper = mid;
    }
    return lower;   /* Because there will alway be a bad version, return lower here */
}