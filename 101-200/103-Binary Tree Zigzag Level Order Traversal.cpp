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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> a;
        if(root==nullptr) return a;
        queue<TreeNode* > q;
        q.push(root);
        int depth=0;
        while(!q.empty())
        {
            a.push_back({});
            int curtotal=q.size();
            int cnt=0;
            while(cnt<curtotal)
            {
                cnt++;
                TreeNode *temp;
                temp=q.front();
                q.pop();
                a[depth].push_back(temp->val);
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
            depth++;
        }
        for(int i=1;i<a.size();i+=2) reverse(a[i].begin(),a[i].end());
        return a;
    }
};