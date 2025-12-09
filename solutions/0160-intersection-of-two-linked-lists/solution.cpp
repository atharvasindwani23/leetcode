/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        if (headA == headB) {
            return headA;
        } 
        map<ListNode*, bool> seen;
        ListNode* curr = headA;
        while (curr) {
            seen[curr] = true;
            curr = curr->next;
        }
        ListNode* temp = headB;
        while (temp) {
            if (seen[temp]) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};
