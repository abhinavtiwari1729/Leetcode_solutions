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
    bool isPalindrome(ListNode* head) {

        // find the middle of linked list 

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != nullptr)
            slow = slow->next;
        
        // reverse linked list with slow as head 


        ListNode* curr = slow;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        while(curr){

            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        //cout << slow->val << slow->next->val;

        while(prev){

            if(prev->val != head->val)
                return false;

            prev = prev->next;
            head = head->next;
        }

        return true;


    }
};
