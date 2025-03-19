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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head;
        std::vector<ListNode*> vec;
        int sum = 0;
        while (curr) {
            sum += curr->val;
            if (curr->val == 0) {
                if (sum != 0) {
               ListNode* flag = new ListNode(sum);
               vec.push_back(flag);
               sum = 0;
                }
            }
            curr = curr->next;
        }
        std::cout << "okay till here?" << std::endl;
        ListNode* returner = vec[0];
        std::cout << "problem here then right" << std::endl;
        for (unsigned int i = 1; i < vec.size(); i++) {
            std::cout << "here?" << std::endl;
            vec[i - 1]->next = vec[i];
        }
        return returner;
    }
};
