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
    ListNode* swapPairs(ListNode* head) {
        // Dummy node acts as a placeholder before the actual head
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        // Ensure there are at least two nodes left to swap
        while (prev->next != nullptr && prev->next->next != nullptr) {
            // Identify the two nodes to be swapped
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Perform the pointer swap
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move the prev pointer two steps forward for the next pair
            prev = first;
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node memory
        return newHead;
    }
};
