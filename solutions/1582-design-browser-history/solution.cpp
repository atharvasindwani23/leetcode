class BrowserHistory {

private:

struct ListNode {
    ListNode* next;
    ListNode* prev;
    string url;
    ListNode(string str) {
        url = str;
    }
};

ListNode* head;
ListNode* tail;
ListNode* curr;

public:
    BrowserHistory(string homepage) {
        head = new ListNode("");
        tail = new ListNode("");
        head->next = tail;
        tail->prev = head;

        ListNode* first = new ListNode(homepage);
        head->next = first;
        first->prev = head;
        first->next = tail;
        tail->prev = first;
        curr = first;
    }
    
    void visit(string url) {
        ListNode* new_url = new ListNode(url);
        new_url->next = tail;
        tail->prev = new_url;
        curr->next = new_url;
        new_url->prev = curr;

        curr = new_url;
    }
    
    string back(int steps) {
        int count = 0;
        while (curr->prev != head && count != steps) {
            curr = curr->prev;
            count++;
        }
            return curr->url;
        }
    
    string forward(int steps) {
         int count = 0;
        while (curr->next != tail && count != steps) {
            curr = curr->next;
            count++;
        }
            return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
