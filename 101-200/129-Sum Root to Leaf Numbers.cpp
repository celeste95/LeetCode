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
private:
    int sum=0;
public:
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
    void dfs(TreeNode* root,int num) {
        if(!root) return;
        if(!root->left&&!root->right) {
            sum+=(10*num+root->val);
            return;
        }
        dfs(root->left,10*num+root->val);
        dfs(root->right,10*num+root->val);
    }
};