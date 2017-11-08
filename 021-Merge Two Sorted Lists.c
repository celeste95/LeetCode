/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3;
    struct ListNode* temp;
//    if(l1->next == NULL && l2->next == NULL) return NULL;
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1->val<=l2->val) 
    {
        l3=l1;
        l1=l1->next;
    }
    else
    {
        l3=l2;
        l2=l2->next;
    }
    temp=l3;
    while(l1&&l2)
    {
        if(l1->val<=l2->val) 
        {
            temp->next=l1;
            l1=l1->next;
            temp=temp->next;
        }
        else
        {
            temp->next=l2;
            l2=l2->next;
            temp=temp->next;
        }
    }
    if(l1==NULL) temp->next=l2;
    if(l2==NULL) temp->next=l1;
    return l3;
}