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
    int pairSum(ListNode* head) {
        std::vector<ListNode*> holder;
        ListNode* curr = head;
        while (curr) {
        holder.push_back(curr);
        curr = curr->next;
        }
        int returner = 0;
        for (int i = 0, j = holder.size() - 1; i < holder.size(), j > i; i++, j--) {
              returner = std::max(returner, holder[i]->val + holder[j]->val);  
        }
        return returner;
    }
    //go through the entire linked list, store elements with corresponding indices in a map or some sort of an array, iterate through the array using two pointers and tabulate the max. 
};
