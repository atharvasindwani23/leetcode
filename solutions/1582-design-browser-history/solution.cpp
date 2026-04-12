class BrowserHistory {

private:

struct ListNode {

ListNode* next;
ListNode* prev;
string url_;
ListNode(string url) {
    url_ = url;
}

};

ListNode* head_;
ListNode* tail_;
ListNode* curr_;

public:
    BrowserHistory(string homepage) {
        head_ = new ListNode("");
        tail_ = new ListNode("");
        ListNode* first = new ListNode(homepage);

        head_->next = first;
        first->prev = head_;
        first->next = tail_;
        tail_->prev = first;

        curr_ = first;

    }   
    
    void visit(string url) {
        ListNode* before = tail_->prev;
        ListNode* newNode = new ListNode(url);
        newNode->next = tail_;
        tail_->prev = newNode;
        before->next = newNode;
        newNode->prev = before;
        curr_->next = newNode;
        newNode->prev = curr_;
        curr_ = newNode;
    }
    
    string back(int steps) {
        int count = 0;

        ListNode* flag = curr_;

        while (flag != head_->next && count != steps) {
            flag = flag->prev;
            count++;
        }
            curr_ = flag;
            return flag->url_;
        return "";
    }
    
    string forward(int steps) {
        int count = 0;

        ListNode* flag = curr_;

        while (flag != tail_->prev && count != steps) {
            flag = flag->next;
            count++;
        }

            curr_ = flag;
            return flag->url_;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
