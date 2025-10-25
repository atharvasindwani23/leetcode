class LRUCache {

private:
    struct ListNode {
        ListNode* next;
        ListNode* prev;
        int key;
        int value;
        ListNode(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    ListNode* head;
    ListNode* tail;
    int capacity_;
    map<int, ListNode*> keyToNode;

    void deleteNode(ListNode* node) {
        ListNode* before = node->prev;
        ListNode* after = node->next;
        before->next = after;
        after->prev = before;
    }

    void insertEnd(ListNode* node) {
        ListNode* before = tail->prev;
        before->next = node;
        node->prev = before;
        node->next = tail;
        tail->prev = node;
    }

    void moveToEnd(ListNode* node) {
        deleteNode(node);
        insertEnd(node);
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
        if (keyToNode.count(key)) {
            ListNode* node = keyToNode[key];
            moveToEnd(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (keyToNode.count(key)) {
            // update existing
            ListNode* node = keyToNode[key];
            node->value = value;
            moveToEnd(node);
            return;
        }

        // evict if needed
        if (keyToNode.size() == capacity_) {
            ListNode* lru = head->next;
            keyToNode.erase(lru->key);
            deleteNode(lru);
        }

        // insert new
        ListNode* newNode = new ListNode(key, value);
        keyToNode[key] = newNode;
        insertEnd(newNode);
    }
};

