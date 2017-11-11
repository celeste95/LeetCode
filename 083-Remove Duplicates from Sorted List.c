/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* now;
    struct ListNode* pre;
    if(head==NULL||head->next==NULL) return head;
    pre=head;
    now=head->next;
    while(now)
    {
        if(pre->val==now->val)
        {
            pre->next=now->next;
            now=pre->next;
        }
        else
        {
            pre=pre->next;
            now=now->next;
        }
    }
    return head;
}
