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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode *tmp=new ListNode(0);
        tmp->next=head;
        ListNode *first=head->next;
        ListNode *second=head;
        ListNode *third=tmp;
        while(1)
        {
            second->next=first->next;
            third->next=first;
            first->next=second;
            if(!second->next) break;
            if(!second->next->next) break;
            third=second;
            first=second->next->next;
            second=second->next;
        }
        return tmp->next;
    }
};