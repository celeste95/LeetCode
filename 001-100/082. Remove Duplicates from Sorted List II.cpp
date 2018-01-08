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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *fake=new ListNode(0);
        fake->next=head;
        ListNode* behind=fake;
        ListNode* mid=head;
        ListNode* front=head;
        while(front)
        {
            if(front->val==mid->val) front=front->next;
            else
            {
                if(mid->next==front)
                {
                    mid=mid->next;
                    behind=behind->next;
                }
                else
                {
                    behind->next=front;
                    mid=front;
                }
            }
        }
        if(mid->next) behind->next=NULL;
        return fake->next;
    }
};