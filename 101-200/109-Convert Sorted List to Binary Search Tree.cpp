/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return new TreeNode(head->val);
        ListNode* temp=head;
        int cnt=0;
        while(temp) {
            cnt++;
            temp=temp->next;
        }
        temp=head;
        int mid = cnt/2;
        ListNode* end;
        while(mid) {
            if(mid==1) end=temp;
            temp=temp->next;
            if(mid==1) end->next=NULL;
            mid--;
        }
        TreeNode* res = new TreeNode(temp->val);
        res->left=sortedListToBST(head);
        res->right=sortedListToBST(temp->next);
        return res;
    }
};