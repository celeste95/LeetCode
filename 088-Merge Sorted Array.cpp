class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i;
        int length=m+n;
        for(i=0;i<n;i++) nums1[m+i]=nums2[i];
        sort(nums1.begin(), nums1.begin()+length);
    }
};


//copy from the end of nums1
//best Solution

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = n-1, j = m-1, pos=m+n-1;
        while (i >= 0 && j >= 0) nums1[pos--] = (nums2[i] >= nums1[j]) ? nums2[i--] : nums1[j--];
        for(; i>=0;i--) nums1[i] = nums2[i];
    }
};
