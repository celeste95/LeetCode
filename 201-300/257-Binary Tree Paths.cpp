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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(!root) return ret;
        
        DFS(ret,root,to_string(root->val));
        return ret;
    }
    
    void DFS(vector<string>& result, TreeNode* root, string t)
    {
        if(!root->left && !root->right) {
            result.push_back(t);
            return;
        }
        if(root->left) DFS(result, root->left, t + "->" + to_string(root->left->val));
        if(root->right) DFS(result, root->right, t + "->" + to_string(root->right->val));
    }
};