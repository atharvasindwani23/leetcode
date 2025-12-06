class LRUCache {
private:
    struct ListNode {
        int key, value;
        ListNode* prev;
        ListNode* next;
        ListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    ListNode* head;
    ListNode* tail;
    int capacity_;
    unordered_map<int, ListNode*> keyToNode;

    void deleteNode(ListNode* node) {
        ListNode* before = node->prev;
        ListNode* after  = node->next;
        before->next = after;
        after->prev = before;
    }

    void addToTail(ListNode* node) {
        ListNode* before = tail->prev;
        before->next = node;
        node->prev = before;
        node->next = tail;
        tail->prev = node;
    }

    void moveToTail(ListNode* node) {
        deleteNode(node);
        addToTail(node);
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
        if (!keyToNode.count(key)) return -1;
        ListNode* node = keyToNode[key];
        moveToTail(node);
        return node->value;
    }

    void put(int key, int value) {
        if (keyToNode.count(key)) {
            ListNode* node = keyToNode[key];
            node->value = value;
            moveToTail(node);
            return;
        }

        if (keyToNode.size() == capacity_) {
            ListNode* lru = head->next;
            deleteNode(lru);
            keyToNode.erase(lru->key);
            delete lru;
        }

        ListNode* node = new ListNode(key, value);
        addToTail(node);
        keyToNode[key] = node;
    }
};

