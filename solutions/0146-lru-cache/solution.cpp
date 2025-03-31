#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void moveToEnd(Node* node) {
        removeNode(node);
        insertAtEnd(node);
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtEnd(Node* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(-1, -1); // Dummy head
        tail = new Node(-1, -1); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        removeNode(node);
        moveToEnd(node); // Mark as most recently used
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            moveToEnd(node);
        } else {
            if (cache.size() == capacity) {
                Node* lru = head->next; // First element is least recently used
                cache.erase(lru->key);
                removeNode(lru);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insertAtEnd(newNode);
        }
    }
};

