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
    bool hasCycle(ListNode* head) {
        ListNode* normal = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            normal = normal->next;
            fast = fast->next->next;
            if (normal == fast) {
                return true;
            }
        }
        return false;
    }
};
