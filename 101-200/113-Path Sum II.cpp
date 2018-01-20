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
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root) return res;
        if(!root->right&&!root->left) {
            if(root->val==sum) {
                res.push_back({});
                res[0].push_back(sum);
            }
            else {
                return res;
            }
        }
        else {
            vector<vector<int>> left(pathSum(root->left, sum-root->val));
            vector<vector<int>> right(pathSum(root->right, sum-root->val));
            for(int i=0;i<left.size();i++) left[i].insert(left[i].begin(),root->val);
            for(int i=0;i<right.size();i++) right[i].insert(right[i].begin(),root->val);
            res.insert(res.end(),left.begin(),left.end());
            res.insert(res.end(),right.begin(),right.end());
        }
        return res;
    }
};