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
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        if (!head->next) {
            return false;
        }
       ListNode* start = head;
       ListNode* ahead = head->next;
       while (start && ahead) {
         if (start == ahead) {
            return true;
         }
         start = start->next;
         if (ahead->next && ahead->next->next) {
         ahead = ahead->next->next;
         } else {
            return false;
         }
       }
       return false;
    }
};
