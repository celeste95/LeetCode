class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* prior=head;
        int len=1;
        while(prior->next)
        {
            len++;
            prior=prior->next;
        }
        prior->next=head;
        int step=len-k%len;
        while(step--)
        {
            prior=prior->next;
            head=head->next;
        }
        prior->next=NULL;
        return head;
    }
};