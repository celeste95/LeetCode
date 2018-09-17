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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr) return nullptr;
        ListNode *walker = head;
        ListNode *runner = head;
        //int cnt=0;
        while(runner->next!=nullptr && runner->next->next!=nullptr) {
            walker = walker->next;
            runner = runner->next->next;
            //cnt++;
            if(walker==runner) {
                walker = head;
                while(walker!=runner) {
                    walker=walker->next;
                    runner=runner->next;
                }
                return walker;
            }
        }
        return nullptr;
    }
};
