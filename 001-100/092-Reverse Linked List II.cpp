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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        int sub=n-m+1;
        ListNode* extra = new ListNode(0);
        ListNode* first = extra;
        ListNode* second = head;
        ListNode* third = head;
        extra->next=head;
        while(m>1)
        {
            first=first->next;
            second=second->next;
            third=third->next;
            m--;n--;
        }
        first->next=NULL;
        while(n--) third=third->next;
        while(sub--)
        {
            ListNode* temp=second;
            second=second->next;
            temp->next=first->next;
            first->next=temp;
        }
        while(first->next) first=first->next;
        first->next=second;
        return extra->next;
    }
};