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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//my solution
        ListNode *tempA=headA;
        ListNode *tempB=headB;
        int lengthA=0,lengthB=0;
        int startA=0,startB=0;
        while(tempA!=NULL) 
        {
            lengthA++;
            tempA=tempA->next;
        }
        while(tempB!=NULL) 
        {
            lengthB++;
            tempB=tempB->next;
        }
        if(lengthA>lengthB) startA=lengthA-lengthB;
        else startB=lengthB-lengthA;
        tempA=headA;
        tempB=headB;
        while(startA--) tempA=tempA->next;
        while(startB--) tempB=tempB->next;
        while(tempA!=tempB && tempA!=NULL)
        {
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};



ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{	//先对齐再遍历 指针A先遍历表A后遍历表B 指针B先遍历表B后遍历表A
	//两个指针都走了lenA+lenB长度 必然同时结束 在便利后半段实现“对齐”
    if(!headA||!headB)  return NULL;
    ListNode *p = headA, *q = headB;
    while(p||q){
        if(p==q)    return p;
        if(!p)  p = headB;
        else if(!q) q = headA;
        else{
            p = p->next;
            q = q->next;
        }
    }
    return NULL;
}