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
    vector<TreeNode*> treegen(int start, int end){
        if(start>end){
            vector<TreeNode*> res;
            return res;
        }
        if(start==end){
            TreeNode* temp= new TreeNode(start);
            vector<TreeNode*> res;
            res.push_back(temp);
            return res;
        }
        else{
            vector<TreeNode*> res;
            for(int i=start;i<=end;i++){
                vector<TreeNode*> left(treegen(start,i-1));
                vector<TreeNode*> right(treegen(i+1,end));
                if(left.size()==0){
                    for(int n=0;n<right.size();n++){
                        TreeNode* temp= new TreeNode(i);
                        temp->right=right[n];
                        res.push_back(temp);
                    }
                }
                if(right.size()==0){
                    for(int m=0;m<left.size();m++){
                        TreeNode* temp= new TreeNode(i);
                        temp->left=left[m];
                        res.push_back(temp);
                    }
                }
                if(right.size()!=0&&left.size()!=0){
                    for(int m=0;m<left.size();m++){
                        for(int n=0;n<right.size();n++){
                            TreeNode* temp= new TreeNode(i);
                            temp->left=left[m];
                            temp->right=right[n];
                            res.push_back(temp);
                        }
                    }
                }
            }
            return res;
        }
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return treegen(1,n);
    }
};