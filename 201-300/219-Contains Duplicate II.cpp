class Solution {
public:
    struct pair
    {
        int val;
        int idx;
        pair(int x,int y) : val(x), idx(y) {}
    };
    
    static bool compare(pair a,pair b)
    {
        if(a.val<b.val) return true;
        if(a.val>b.val) return false;
        if(a.val==b.val)
        {
            if(a.idx<b.idx) return true;
            if(a.idx>b.idx) return false;
        }
    }
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<struct pair> pairs;
        for(int i=0;i<nums.size();i++)
        {
            pairs.push_back(pair(nums[i],i));
        }
        
        sort(pairs.begin(),pairs.end(),compare);
        for(int i=1;i<nums.size();i++)
        {
            if(pairs[i-1].val==pairs[i].val&&(pairs[i].idx-pairs[i-1].idx)<=k) return true;
        }
        return false;
    }
};



class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //example 
        if(k<=0||k>=35000) return false;
        if(k>=nums.size())k=nums.size()-1;
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size()&&j<=i+k;j++)
                if(nums[i]==nums[j]) return true;
        return false;
    }
};