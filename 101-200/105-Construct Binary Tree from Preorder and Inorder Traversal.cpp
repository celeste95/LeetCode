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
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        if(preorder.size()==0) return nullptr;
        if(inorder.size()==0) return nullptr;
        TreeNode* res=new TreeNode(preorder[0]);
        if(preorder.size()==1) return res;
        int i,j;
        for(i=0;i<inorder.size();i++) if(preorder[0]==inorder[i]) break;
        vector<int> newpreleft(preorder.begin()+1,preorder.begin()+i+1);
        vector<int> newinleft(inorder.begin(),inorder.begin()+i);
        res->left=buildTree(newpreleft,newinleft);
        vector<int> newpreright(preorder.begin()+i+1,preorder.end());
        vector<int> newinright(inorder.begin()+i+1,inorder.end());
        res->right=buildTree(newpreright,newinright);
        return res;
    }
};