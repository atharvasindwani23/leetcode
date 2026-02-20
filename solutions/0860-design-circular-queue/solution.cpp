class MyCircularQueue {

private:

struct ListNode {
    ListNode* next;
    ListNode* prev;
    int value;

    ListNode(int val) {
        value = val;
    }
};

ListNode* head;
ListNode* tail;
int capacity;
int size = 0;


public:
    MyCircularQueue(int k) {
        capacity = k;
        head = new ListNode(-1);
        tail = new ListNode(-1);

        head->next = tail;
        tail->prev = head;
    }
    
    bool enQueue(int value) {
        //insert at back
        //delete at front
        if (size == capacity) {
            return false;
        }

        size++;
        ListNode* curr = new ListNode(value);
        ListNode* before = tail->prev;
        ListNode* after = tail;

        before->next = curr;
        curr->prev = before;
        after->prev = curr;
        curr->next = after;
        return true;
    }

    
    bool deQueue() {
        if (size == 0) {
            return false;
        }
        size--;
        head = head->next;
        return true;
    }
    
    int Front() {
        if (size == 0) {
            return -1;
        }
        return head->next->value;
    }
    
    int Rear() {
        if (size == 0) {
            return -1;
        }
        return tail->prev->value;
        
    }
    
    bool isEmpty() {
        return (size ==0);
    }
    
    bool isFull() {
        return (size == capacity);
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
