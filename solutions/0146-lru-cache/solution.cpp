class LRUCache {

private:

struct ListNode {
int key = 0;
int value = 0;
ListNode* next;
ListNode* prev;

ListNode(int k, int v) {
    key = k;
    value = v;   
}

};

void deleteNode(ListNode* curr) {
    ListNode* before = curr->prev;
    ListNode* after = curr->next;
    before->next = after;
    after->prev = before;
}

void addToTail(ListNode* curr) {
    ListNode* before = tail->prev;
    before->next = curr;
    curr->next = tail;
    curr->prev = before;
    tail->prev = curr;
}
void moveToTail(ListNode* curr) {
    deleteNode(curr);
    addToTail(curr);
}
ListNode* head;
ListNode* tail;
int capacity_ = 0;
unordered_map<int, ListNode*> lru;


public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (lru.contains(key)) {
            moveToTail(lru[key]);
            return lru[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (lru.contains(key)) {
            ListNode* currNode = lru[key];
            currNode->value = value;
            moveToTail(currNode);
            return;
        }
        if (capacity_ == lru.size()) {
            ListNode* evict = head->next;
            int k  = evict->key;
            deleteNode(evict);
            lru.erase(k);
            delete evict;
        }
        ListNode* newNode = new ListNode(key, value);
        addToTail(newNode);
        lru[key] = newNode;
    } 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
