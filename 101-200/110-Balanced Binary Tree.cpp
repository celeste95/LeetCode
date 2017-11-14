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
	//my solution 9ms
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        else return max(maxDepth(root->left) , maxDepth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int subdepth=maxDepth(root->left)-maxDepth(root->right);
        if(subdepth!=1&&subdepth!=0&&subdepth!=-1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};


class Solution {
	//example solution 6ms
public:
    bool isBalanced(TreeNode* root) {
        // check its height
        // since the height of any subtree is >= 0,
        // we use -1 to indicate not balanced
        return height(root) != -1;
    }
    
    int height(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int lh = height(root->left);
        if(lh == -1) {
            return -1;
        }
        int rh = height(root->right);
        if(rh == -1) {
            return -1;
        }
        if(abs(rh - lh) > 1) {
            return -1;
        }
        
        return 1 + max(lh, rh);
    }
};