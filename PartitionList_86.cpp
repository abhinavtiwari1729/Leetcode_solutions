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
    ListNode* partition(ListNode* head, int x) {

        ListNode before(0) , after(0);
        ListNode* before_curr = &before;
        ListNode* after_curr = &after;

        while(head) {
            if(head->val < x){
                before_curr->next = head;
                before_curr = before_curr->next;
            }
            else{
                after_curr->next = head;
                after_curr = after_curr->next;
            }

            head = head->next;
        }

        before_curr->next = after.next;
        after_curr->next = nullptr;

        return before.next;

    }
};
