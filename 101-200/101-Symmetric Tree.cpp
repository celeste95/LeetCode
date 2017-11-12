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
    bool isSymmetric(TreeNode* root) {
        //my iteration solution
        if(root==NULL) return true;
        if(!(root->left||root->right)) return true;
        if((root->left==NULL)^(root->right==NULL)) return false;
        if(root->left->val!=root->right->val) return false;
        //TreeNode* temp1=&TreeNode(1),temp2=&TreeNode(1);
        //temp1=TreeNode(1);
        //temp2=TreeNode(1);
        TreeNode t1(1),t2(1);
        TreeNode *temp1,*temp2;
        temp1=&t1;
        temp2=&t2;
        temp1->left=root->left->left;
        temp1->right=root->right->right;
        temp2->left=root->left->right;
        temp2->right=root->right->left;
        return isSymmetric(temp1)&&isSymmetric(temp2);
    }


};

//example iteration solution
class Solution {
    bool isSymmetric(TreeNode *node1, TreeNode *node2) {
        if (node1 == nullptr && node2 == nullptr) return true;
        if (node1 == nullptr || node2 == nullptr) return false;
        return node1->val == node2->val &&
               isSymmetric(node1->left, node2->right) &&
               isSymmetric(node1->right, node2->left);
    }
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        return isSymmetric(root->left, root->right);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        if(!(root->left||root->right)) return true;
        if((root->left==NULL)^(root->right==NULL)) return false;
        if(root->left->val!=root->right->val) return false;
    }
};


//
