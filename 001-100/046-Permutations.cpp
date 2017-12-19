class Solution {
    //TLE
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size()==0) return ret;
        vector<int> perm;
        if(nums.size()==1)
        {
            perm.push_back(nums[0]);
            ret.push_back(perm);
            return ret;
        }
        for(int i=0;i<nums.size();i++)
        {
            int temp=nums[i];
            swap(nums[i],nums[nums.size()-1]);
            nums.pop_back();
            for(int j=0;j<permute(nums).size();j++)
            {
                vector<int> perm(permute(nums)[j]);
                perm.push_back(temp);
                ret.push_back(perm);
            }
            nums.push_back(temp);
            swap(nums[i],nums[nums.size()-1]);
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
};