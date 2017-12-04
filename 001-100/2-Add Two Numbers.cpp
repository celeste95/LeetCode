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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//my Solution
        ListNode *ret;
        ListNode *temp = new ListNode(0);
        ret = temp;
        int carry=0,sum=0;
        while(l1&&l2)
        {
            sum=(l1->val+l2->val+carry);
            if(sum/10)
            {
                carry=1;
                temp->val=sum%10;
            }
            else
            {
                carry=0;
                temp->val=sum;
            }
            l1=l1->next;
            l2=l2->next;
            if(l1||l2)
            {
                temp->next=new ListNode(0);
                temp=temp->next;
            }
        }
        while(l1)
        {
            while(l1)
            {
                sum=(l1->val+carry);
                if(sum/10)
                {
                    carry=1;
                    temp->val=sum%10;
                }
                else
                {
                    carry=0;
                    temp->val=sum;
                }
                l1=l1->next;
                if(l1)
                {
                    temp->next=new ListNode(0);
                    temp=temp->next;
                }
            }
        }
        while(l2)
        {
            sum=(l2->val+carry);
            if(sum/10)
            {
                carry=1;
                temp->val=sum%10;
            }
            else
            {
                carry=0;
                temp->val=sum;
            }
            l2=l2->next;
            if(l2)
            {
                temp->next=new ListNode(0);
                temp=temp->next;
            }
        }
        if(carry) temp->next=new ListNode(1);
        return ret;
    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
    {
		//example
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
    }
};