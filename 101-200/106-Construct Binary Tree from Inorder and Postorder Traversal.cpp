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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0) return nullptr;
        if(inorder.size()==0) return nullptr;
        TreeNode* res=new TreeNode(postorder[postorder.size()-1]);
        if(postorder.size()==1) return res;
        int i;
        for(i=0;i<inorder.size();i++) if(postorder[postorder.size()-1]==inorder[i]) break;
        vector<int> newpostleft(postorder.begin(),postorder.begin()+i);
        vector<int> newinleft(inorder.begin(),inorder.begin()+i);
        res->left=buildTree(newinleft,newpostleft);
        vector<int> newpostright(postorder.begin()+i,postorder.end()-1);
        vector<int> newinright(inorder.begin()+i+1,inorder.end());
        res->right=buildTree(newinright,newpostright);
        return res;
    }
};