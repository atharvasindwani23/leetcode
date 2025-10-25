class BrowserHistory {

private:

        struct ListNode {
            ListNode* next;
            ListNode* prev;
            string value;
            ListNode(string str) {
                value = str;
            }
        };
    ListNode* head;
    ListNode* tail;
    ListNode* current;

public:
    BrowserHistory(string homepage) {
        ListNode* curr = new ListNode(homepage);
        head = new ListNode("");
        tail = new ListNode("");
        head->next = curr;
        curr->prev = head;
        curr->next = tail;
        tail->prev = curr;
        current = curr;
    }
    
    void visit(string url) {
        ListNode* urlNode = new ListNode(url);
        current->next = urlNode;
        urlNode->prev = current;
        urlNode->next = tail;
        tail->prev = urlNode;
        current = urlNode;
    }
    
    string back(int steps) {
        int counter = 0;
        ListNode* flag = current;
        while (counter != steps && flag != head->next) {
            flag = flag->prev;
            counter++;
        }
        if (counter == steps) {
            current = flag;
            return current->value;
        }
        current = head->next;
        return current->value;
    }
    
    string forward(int steps) {
        int counter = 0;
        ListNode* flag = current;
        while (counter != steps && flag != tail->prev) {
            flag = flag->next;
            counter++;
        }
        if (counter == steps) {
            current = flag;
            return current->value;
        }
        current = tail->prev;
        return current->value;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
