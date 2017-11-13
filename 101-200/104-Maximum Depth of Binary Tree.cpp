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
    int maxDepth(TreeNode* root) {
		//Time Limit Exceeded 
        if(root==nullptr) return 0;
        else return maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left)+1 : maxDepth(root->right) +1;
    }
	
	int maxDepth(TreeNode* root) {
		//Accepted
        if(root==nullptr) return 0;
        queue<TreeNode* > q;
        q.push(root);
        int depth=0;
        while(!q.empty())
        {
            depth++;
            int curtotal=q.size();
            int cnt=0;
            while(cnt<curtotal)
            {
                cnt++;
                TreeNode *temp;
                temp=q.front();
                q.pop();
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
        }
        return depth;
    }
};