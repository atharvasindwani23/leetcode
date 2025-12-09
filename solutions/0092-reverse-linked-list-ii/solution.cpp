class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: Move prev to the node before "left"
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* leftNode = prev->next;

        // Step 2: Move curr to "right"
        ListNode* curr = leftNode;
        for (int i = left; i < right; i++) {
            curr = curr->next;
        }

        ListNode* rightNode = curr;
        ListNode* afterRight = curr->next;

        // Step 3: Reverse from leftNode up to (but not including) afterRight
        ListNode* newHead = reverseList(leftNode, afterRight);

        // Step 4: Reconnect
        prev->next = newHead;
        leftNode->next = afterRight;

        return dummy.next;
    }

    // Reverse from start up to (not including) end
    ListNode* reverseList(ListNode* start, ListNode* end) {
        ListNode* prev = end;
        ListNode* curr = start;

        while (curr != end) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;  // new head of reversed segment
    }
};

