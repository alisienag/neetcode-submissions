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
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* ptr = head;
        int size = 1;
        while (ptr->next) {
            size++;
            ptr = ptr->next;
        }

        int idx_to_remove = size - n;

        ptr = head;
        for (int i = 0; i < idx_to_remove-1; i++) {
            ptr = ptr->next;
        }

        if (idx_to_remove == 0) {
            ListNode* next = ptr->next;
            head->next = nullptr;
            return next;
        }

        ListNode* nextnext = ptr->next->next;
        ptr->next = nextnext;
        return head;
    }
};
