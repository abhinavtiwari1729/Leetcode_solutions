/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode * slow_prev = nullptr;
        ListNode * fast_p = head;
        ListNode * slow_p = head ;

        while(fast_p && fast_p->next) {

            slow_prev = slow_p ;
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;

        }

        if(slow_p == fast_p)
            return nullptr;
        slow_prev->next = slow_p->next;

        return head;




    }
};
