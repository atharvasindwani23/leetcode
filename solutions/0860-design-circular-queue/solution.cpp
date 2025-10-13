class MyCircularQueue {
private:
    struct ListNode {
    ListNode* next;
    ListNode* prev;
    int value;
    ListNode(int k) {
        value = k;
        prev = nullptr;
        next = nullptr;
        }
    };
    ListNode* head;
    ListNode* tail;
    int capacity;
    int size;

        void insertAtEnd(ListNode* curr) {
        ListNode* before = tail->prev;
        ListNode* after = tail;
        before->next = curr;
        curr->prev = before;
        curr->next = tail;
        tail->prev = curr;
    }



public:
       MyCircularQueue(int k) {
        capacity = k;
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    bool enQueue(int value) {
        ListNode* curr = new ListNode(value);
        if (size == capacity) {
            return false;
        }
        insertAtEnd(curr);
        size++;
        return true;
    }
    
    bool deQueue() {
        if (size == 0) {
            return false;
        }
        head = head->next;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) {
            return -1;
        }
        return head->next->value;
    }


    //do it using a linked least -> head and tail can be dummy?
    
    int Rear() {
        if(isEmpty()) {
            return -1;
        }
        return tail->prev->value;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
