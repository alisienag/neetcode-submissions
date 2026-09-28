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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        int size = 1;
        ListNode* ptr = head;
        while (ptr->next != nullptr) {
            size++;
            ptr = ptr->next;
        }

        int midpoint = (size+1)/2;
        ptr = head;
        for (int i = 0; i < midpoint - 1; i++) {
            ptr = ptr->next;
        }

        ListNode* back = ptr->next;
        ptr->next = nullptr;

        std::stack<ListNode*> backward;
        while (back != nullptr) {
            backward.push(back);
            back = back->next;
        }

        ptr = head;
        while (!backward.empty()) {
            ListNode* next = ptr->next;

            ptr->next = backward.top();
            backward.pop();
            ptr->next->next = next;

            ptr = ptr->next->next;
        }
    }
};
