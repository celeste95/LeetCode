/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> list;
        ListNode *temp=head;
        //if(!head) return false;
        while(temp)
        {
            list.push_back(temp->val);
            temp=temp->next;
        }
        for(int i=0;i<list.size()/2;i++)
        {
            if(list[i]!=list[list.size()-1-i]) return false;
        }
        return true;
    }
};
