class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            bool isDuplicate = false;
            while (curr->next && curr->val == curr->next->val) {
                isDuplicate = true;
                ListNode* toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;
            }

            if (isDuplicate) {
                ListNode* toDelete = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete toDelete;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
