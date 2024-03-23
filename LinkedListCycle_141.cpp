class Solution {
public:
    bool hasCycle(ListNode *head) {
        
         ListNode* slow_ptr = head;
         ListNode* fast_ptr = head;

         while(fast_ptr && fast_ptr->next){
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;

            if(slow_ptr == fast_ptr)
                return true;

         }

        return false;
    }
};
