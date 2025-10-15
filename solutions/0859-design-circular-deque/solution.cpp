class MyCircularDeque {

private:
        struct ListNode {
        ListNode* next;
        ListNode* prev;
        int value;
        ListNode(int v) {
            value = v;
        }
        };
        ListNode* head;
        ListNode* tail;
        int capacity;
        int size = 0;


public:
    MyCircularDeque(int k) {
        capacity = k;
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head->next = tail;
        tail->prev= head;
    }
    
    bool insertFront(int value) {
        if (capacity == size) {
            return false;
        }
        ListNode* after = head->next;
        ListNode* before = head;
        ListNode* curr = new ListNode(value);
        before->next = curr;
        curr->prev = before;
        curr->next = after;
        after->prev = curr;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (capacity == size) {
            return false;
        }
        ListNode* after = tail;
        ListNode* before = tail->prev;
        ListNode* curr = new ListNode(value);
        curr->prev = before;
        before->next = curr;
        curr->next = after;
        after->prev = curr;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (size == 0) {
            return false;
        }
        head = head->next;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (size == 0) {
            return false;
        }   
        tail = tail->prev;
        size--;
        return true;
    }
    
    int getFront() {
        if (size == 0) {
            return -1;
        }
        return head->next->value;
    }
    
    int getRear() {
        if (size == 0) {
            return -1;
        }
        return tail->prev->value;

    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return capacity == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
