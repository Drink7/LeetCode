class Node {
public:
    int key = 0;
    int value = 0;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node(int k, int v) {
        key = k;
        value = v;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        // O(1) -> double linked list
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;

        volume = capacity;
    }
    
    int get(int key) {
        if (dict.count(key) < 1) {
            return -1;
        }

        Node* node = dict[key];
        remove(node);
        insert(head, node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (dict.count(key) > 0) {
            Node* node = dict[key];
            node->value = value;
            remove(node);
            insert(head, node);
        } else {
            Node* newNode = new Node(key, value);
            dict[key] = newNode;
            insert(head, newNode);
            if (dict.size() > volume) {
                dict.erase(tail->prev->key);
                remove(tail->prev);
            }
        }
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* prev, Node* node) {
        node->next = prev->next;
        node->prev = prev;

        prev->next->prev = node;
        prev->next = node;
    }
private:
    Node* head;
    Node* tail;
    unordered_map<int, Node*> dict;
    int volume = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */