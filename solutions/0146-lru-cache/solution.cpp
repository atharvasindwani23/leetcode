class LRUCache {

private:
struct ListNode {

    ListNode* next;
    ListNode* prev;

    int key;
    int value;

    ListNode(int k, int v) {
        key = k;
        value = v;
    }
};

ListNode* tail_;
ListNode* head_;
int capacity_;
unordered_map<int, ListNode*> keyToNode;

void deleteNode(ListNode* curr) {
    ListNode* before = curr->prev;
    ListNode* after = curr->next;

    before->next = after;
    after->prev = before;
}

void addNodeToTail(ListNode* curr) {
    ListNode* before = tail_->prev;
    before->next = curr;
    curr->next = tail_;
    tail_->prev = curr;
    curr->prev = before;
}

void moveToEnd(ListNode* curr) {
    deleteNode(curr);
    addNodeToTail(curr);
}

public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        head_ = new ListNode(-1, -1);
        tail_ = new ListNode(-1, -1);

        head_->next = tail_;
        tail_->prev = head_;
    }
    
    int get(int key) {
        if (keyToNode.count(key)) {
            ListNode* curr = keyToNode[key];
            moveToEnd(curr);
            return curr->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (keyToNode.count(key)) {
            ListNode* node = keyToNode[key];
            node->value = value;
            moveToEnd(node);
            return;
        }
        if (capacity_ == keyToNode.size()) {
            ListNode* deleted = head_->next;
            keyToNode.erase(deleted->key);
            deleteNode(deleted);
            delete deleted;
        }
        ListNode* newNode = new ListNode(key, value);
        addNodeToTail(newNode);
        keyToNode[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
