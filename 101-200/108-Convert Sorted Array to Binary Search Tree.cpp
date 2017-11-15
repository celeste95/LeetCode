/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	//my Solution 19ms
public:
    vector<int> divide(vector<int> nums,int start,int end)
    {
        vector<int> temp;
        if(start==end) return temp;
        for(int i=start;i<end;i++)
        {
            temp.push_back(nums[i]);
        }
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int> nums) {
        if(nums.size()==0) return NULL;
        if(nums.size()==1)
        {
            TreeNode *ptr=new TreeNode(nums[0]);
            return ptr;
        }
        TreeNode *ptr=new TreeNode(nums[nums.size()/2]);
        ptr->left=sortedArrayToBST(divide(nums,0,nums.size()/2));
        ptr->right=sortedArrayToBST(divide(nums,nums.size()/2+1,nums.size()));
        return ptr;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	//example Solution
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        return sort(nums,0,nums.size()-1);
    }
    TreeNode* sort(vector<int>&nums,int start,int end)
    {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=sort(nums,start,mid-1);
        root->right=sort(nums,mid+1,end);
        return root;
    }
};