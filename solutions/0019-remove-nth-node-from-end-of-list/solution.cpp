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
        ListNode* new_head =  reverse(head);
        int count = 1;
        ListNode* copy = new_head;
        if (n == 1) {
            new_head = new_head->next;
            return reverse(new_head);
        }
        while (count != n - 1) {
            copy = copy->next;
            count++;
        }
        copy->next = copy->next->next;
        return reverse(new_head);
    }

    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;
    }
};
