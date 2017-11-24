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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode *dummy=new ListNode(0);
        ListNode *temp=head;
        while(head)
        {
            head=head->next;
            temp->next=dummy->next;
            dummy->next=temp;
            temp=head;
        }
        return dummy->next;
    }
};