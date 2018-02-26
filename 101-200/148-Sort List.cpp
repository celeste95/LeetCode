/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* get_partion(ListNode* start, ListNode* end) {
        int key=start->val;
        ListNode* p=start;
        ListNode* q=p->next;
        while(q!=end) {
            if(q->val < key) {
                p=p->next;
                swap(p->val,q->val);
            }
            q=q->next;
        }
        swap(p->val,start->val);
        return p;
    }
    void quicksort(ListNode* start, ListNode* end) {
        if(start==end) return;
        ListNode* partion=get_partion(start,end);
        quicksort(start,partion);
        quicksort(partion->next,end);
        return;
    }
public:
    ListNode* sortList(ListNode* head) {
        //if(!head) return NULL;
        // ListNode* start=head;
        // while(head) {
        //     head=head->next;
        // }
        // ListNode* end=head;
        quicksort(head,NULL);
        return head;
    }
};