class BrowserHistory {

private:

        struct ListNode {
        string value;
        ListNode* next;
        ListNode* prev;
        ListNode(string str) {
            value = str;
        }
    };

    ListNode* head;
    ListNode* tail;
    ListNode* currPos;

public:

    BrowserHistory(string homepage) {

        head = new ListNode("");
        tail = new ListNode("");
        ListNode* curr = new ListNode(homepage);
        head->next = curr;
        curr->prev = head;
        curr->next = tail;
        tail->prev = curr;
        currPos = curr;
    }
    
    void visit(string url) {
        currPos->next = tail;
        tail->prev = currPos;
        ListNode* newUrl = new ListNode(url);
        currPos->next = newUrl;
        newUrl->prev = currPos;
        newUrl->next = tail;
        tail->prev = newUrl;
        currPos = newUrl;
    }
    
    string back(int steps) {
        int step = 0;
        while (currPos != head && step != steps) {
            currPos = currPos->prev;
            step++;
        }
        if (currPos == head) {
            currPos = currPos->next;
            return currPos->value;
        }
        return currPos->value;
    }
    
    string forward(int steps) {
        int step = 0;
        while (currPos != tail && step != steps) {
            currPos = currPos->next;
            step++;
        }
        if (currPos == tail) {
            currPos = currPos->prev;
            return currPos->value;
        }
        return currPos->value;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
