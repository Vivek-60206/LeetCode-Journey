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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            // 1. Find the k-th node from groupPrev
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) break; // Fewer than k nodes left; stop

            ListNode* groupNext = kth->next;

            // 2. Reverse the k nodes in-place
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            while (curr != groupNext) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            // 3. Reconnect the reversed group with the previous part
            ListNode* tmp = groupPrev->next; // Original start is now the end of this group
            groupPrev->next = kth;           // kth is now the start of this group
            groupPrev = tmp;                 // Advance groupPrev for the next group
        }

        return dummy.next;
    }

private:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
