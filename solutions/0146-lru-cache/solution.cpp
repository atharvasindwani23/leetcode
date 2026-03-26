class LRUCache {

struct ListNode {

    ListNode* next;
    ListNode* prev;
    int key = 0;
    int value = 0;
    ListNode(int k, int v) {
        key = k;
        value = v;
    }
};

ListNode* head;
ListNode* tail;
int capacity_ = 0;

unordered_map<int, ListNode*> keyToNode;

//is to delete curr posn
//add to end

void deleteNode(ListNode* curr) {
    ListNode* before = curr->prev;
    ListNode* after = curr->next;

    before->next = after;
    after->prev = before;
}

void addToEnd(ListNode* curr) {
    ListNode* after = tail;
    ListNode* before = tail->prev;
    curr->next = after;
    after->prev = curr;
    before->next = curr;
    curr->prev = before;
}

void move(ListNode* curr) {
    deleteNode(curr);
    addToEnd(curr);
}

public:
    LRUCache(int capacity) {
       capacity_ = capacity;
       head = new ListNode(-1, -1);
       tail = new ListNode(-1, -1);
       head->next = tail;
       tail->prev = head; 
    }
    
    int get(int key) {
        if (!keyToNode.count(key)) {
            return -1;
        }
        ListNode* curr = keyToNode[key];
        move(curr);
        return curr->value;
    }
    
    void put(int key, int value) {
        if (keyToNode.count(key)) {
            ListNode* curr = keyToNode[key];
            curr->value = value;
            move(curr);
        } else {
            ListNode* newKey = new ListNode(key, value);
            addToEnd(newKey);
            keyToNode[key] = newKey;
        }
        if (keyToNode.size() > capacity_) {
                ListNode* lru = head->next;   // least recently used
                deleteNode(lru);
                keyToNode.erase(lru->key);
                delete lru;
            }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
