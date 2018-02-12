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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return NULL;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        head=head->next;
        dummy->next->next=NULL;
        while(head) {
            ListNode* temp=head;
            head=head->next;
            ListNode* first=dummy->next;
            ListNode* second=dummy;
            while(first&&first->val<temp->val) {
                first=first->next;
                second=second->next;
            }
            temp->next=first;
            second->next=temp;
        }
        return dummy->next;
    }
};