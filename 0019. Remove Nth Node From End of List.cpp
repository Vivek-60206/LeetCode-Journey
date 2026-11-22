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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node handles edge cases smoothly (e.g., removing the actual head)
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // 1. Advance 'fast' so there is a gap of n nodes between 'fast' and 'slow'
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // 2. Move both pointers until 'fast' reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 3. 'slow' is now right before the target node; unlink and delete it
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        // 4. Clean up dummy node and return the new head
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
