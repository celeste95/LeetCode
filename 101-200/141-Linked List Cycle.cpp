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
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        ListNode *walker = head;
        ListNode *runner = head;
        while(runner->next!=nullptr && runner->next->next!=nullptr) {
            walker = walker->next;
            runner = runner->next->next;
            if(walker==runner) return true;
        }
        return false;
    }
};

// 1.Use two pointers, walker and runner.
// 2.walker moves step by step. runner moves two steps at time.
// 3.if the Linked List has a cycle walker and runner will meet at some point.