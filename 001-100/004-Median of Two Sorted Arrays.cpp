class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int l = (m + n + 1) / 2;  
        int r = (m + n + 2) / 2;  
        return (getkth(nums1, m ,nums2, n, l) + getkth(nums1, m, nums2, n, r)) / 2.0;  
    }
    
    int getkth(vector<int>& s, int m, vector<int>& l, int n, int k){  
        //确保m < n   
        if (m > n)   
            return getkth(l, n, s, m, k);  
        if (m == 0)  
            return l[k - 1];  
        if (k == 1)  
            return min(s[0], l[0]);  
    //递归过程  
        int i = min(m, k / 2), j = min(n, k / 2);  
        if (s[i - 1] > l[j - 1]) { 
            vector<int> temp(l.begin() + j, l.end());
            return getkth(s, m, temp, n - j, k - j);  
        }
        else{
            vector<int> temp(s.begin() + i, s.end());
            return getkth(temp, m - i, l, n, k - i);  
        }
        return 0;  
    }  
};