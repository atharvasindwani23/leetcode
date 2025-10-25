class MyCircularDeque {

private:

    struct ListNode {
        
    ListNode* next;
    ListNode* prev;
    int value;
    ListNode(int val) {
    value = val;
    }
};
    
    int capacity = 0;
    int size = 0;
    ListNode* head;
    ListNode* tail;

public:
    MyCircularDeque(int k) {
        capacity = k;
        head = new ListNode(-1);
        tail  = new ListNode(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    bool insertFront(int value) {
     if (size == capacity) {
        return false;
     }
     ListNode* curr = new ListNode(value);
     ListNode* after = head->next;
     head->next = curr;
     curr->prev = head;
     after->prev = curr;
     curr->next = after;
     size++;
     return true;
    }
    bool insertLast(int value) {
         if (capacity == size) {
            return false;
        }
        ListNode* before = tail->prev;
        ListNode* curr = new ListNode(value);
        before->next = curr;
        curr->prev = before;
        curr->next = tail;
        tail->prev = curr;
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

    // lets think of a conventional queue, we add to the top and delete from the top
    //the thing which is different now is that we also want this ability towards the tail
    // so can we think of a data strcture through which we can quickly add and delete from the end and the start?
    //yes, we can this is a prime example of a doubly linked list! 
    
    int getFront() {
        if (size != 0) {
        return head->next->value;
        }
        return -1;
    }
    
    int getRear() {
        if (size != 0) {
        return tail->prev->value;
        }
        return -1;
    }
    
    bool isEmpty() {
     return (size == 0);   
    }
    
    bool isFull() {
        return (capacity == size);
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
