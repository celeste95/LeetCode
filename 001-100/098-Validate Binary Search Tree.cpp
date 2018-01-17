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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!root->left&&!root->right) return true;
        TreeNode* templeft=root->left;
        TreeNode* tempright=root->right;
        if(!templeft){
            while(tempright->left) tempright=tempright->left;
            return isValidBST(root->right)&&tempright->val>root->val;
        }
        if(!tempright){
            while(templeft->right) templeft=templeft->right;
            return isValidBST(root->left)&&templeft->val<root->val;
        }
        while(templeft->right) templeft=templeft->right;
        while(tempright->left) tempright=tempright->left;
        return isValidBST(root->right)&&tempright->val>root->val&&isValidBST(root->left)&&templeft->val<root->val;
    }
};