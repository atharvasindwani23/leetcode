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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* returner = new ListNode(); //marks the start of our new list;
    ListNode* curr_1 = list1;
    ListNode* curr_2 = list2;
    ListNode* curr_3; // curr for our new list, we will be appending things to our list using this
    if (curr_1 && curr_2) {
        if (curr_1-> val < curr_2->val) {
            returner = curr_1;
            curr_1 = curr_1->next;
        } else {
            returner = curr_2;
           curr_2 = curr_2->next;
        }
    } else {
        if (curr_1) {
            returner = curr_1;
            curr_1 = curr_1->next;
        } else if (curr_2) {
            returner = curr_2;
            curr_2 = curr_2->next;
        } else {
            return nullptr;
        }
    }
    curr_3 = returner;
    while (curr_1 && curr_2) {
         if (curr_1->val <= curr_2->val) {
            curr_3->next = new ListNode(curr_1->val);
            curr_3 = curr_3->next;
            curr_1 = curr_1->next;
         } else {
            curr_3->next = new ListNode(curr_2->val);
            curr_3 = curr_3->next;
            curr_2 = curr_2->next;
         }
    }
    while (curr_1) {
        curr_3 -> next = new ListNode(curr_1->val);
        curr_3 = curr_3->next;
        curr_1 = curr_1->next;
    }
    while (curr_2) {
        curr_3 -> next = new ListNode(curr_2->val);
        curr_3 = curr_3->next;
        curr_2 = curr_2->next;
    }
    return returner;
}

};
