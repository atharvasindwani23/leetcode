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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        while (lists.size() > 1) {
            lists.push_back(mergeTwoSortedLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }

    ListNode* mergeTwoSortedLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }
        if (list1->val <= list2->val) {
            list1->next = mergeTwoSortedLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoSortedLists(list1, list2->next);
            return list2;
        }
    }
};
