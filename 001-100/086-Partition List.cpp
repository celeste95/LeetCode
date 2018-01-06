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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less=new ListNode(0);
        ListNode* more=new ListNode(0);
        ListNode* temp=head;
        ListNode* lesstemp=less;
        ListNode* moretemp=more;
        while(temp)
        {
            if(temp->val<x)
            {
                lesstemp->next=new ListNode(temp->val);
                lesstemp=lesstemp->next;
            }
            else
            {
                moretemp->next=new ListNode(temp->val);
                moretemp=moretemp->next;
            }
            temp=temp->next;
        }
        lesstemp->next=more->next;
        return less->next;
    }
};
