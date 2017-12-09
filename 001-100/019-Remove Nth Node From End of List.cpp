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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre=head;
        ListNode *del=head;
        ListNode *temp=new ListNode(0);
        ListNode *start=temp;
        temp->next=head;
        while(n-->1)
        {
            pre=pre->next;
        }
        while(pre->next)
        {
            del=del->next;
            pre=pre->next;
            temp=temp->next;
        }
        temp->next=del->next;
        return start->next;
    }
};