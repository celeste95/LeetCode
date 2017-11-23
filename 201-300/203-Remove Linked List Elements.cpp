class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		//my solution 39ms
        ListNode *now,*pre;
        while(head && head->val==val) head=head->next;
        if(!head) return head;
        if(!head->next) return head;
        pre=head;
        now=head->next;
        while(now)
        {
            if(now->val!=val)
            {
                pre=pre->next;
                now=now->next;
            }
            else
            {
                now=now->next;
                pre->next=now;
            }
        }
        return head;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		//example solution 23ms
        ListNode *Dummy = new ListNode(0);
        Dummy->next = head;
        head = Dummy;
        while(head != nullptr){
            if(head->next != nullptr && head->next->val == val){
                head->next = head->next->next;
            }
            else{
                head = head->next;
            }
        }
        return Dummy->next;
    }
};