class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        while(head != NULL) {
             ListNode *curr = head;
             head = head->next;
             curr->next = prev;
             prev = curr;
        }
        return prev;
    }
};