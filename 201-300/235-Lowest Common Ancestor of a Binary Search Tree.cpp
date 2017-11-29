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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//26ms
        if(p->val<=root->val&&q->val>=root->val) return root;
        if(q->val<=root->val&&p->val>=root->val) return root;
        if(p->val<root->val&&q->val<root->val) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//23ms
        if(p->val<root->val&&q->val<root->val) return lowestCommonAncestor(root->left,p,q);
        if(p->val>root->val&&q->val>root->val) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};