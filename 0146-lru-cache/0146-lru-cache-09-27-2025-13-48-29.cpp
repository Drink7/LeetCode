class Node {
public:
    int key = -1;
    int val = -1;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node () {
    }
    Node(int v1, int v2, Node* n1, Node* n2) {
        key = v1;
        val = v2;
        prev = n1;
        next = n2;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        // O(1)
        // hash table -> unordered_map<int, Node*>
        cacheSize = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (dict.count(key) < 1) {
            return -1;
        } else {
            // find, update node
            Node* node = dict[key];
            erase(node);
            insertHead(node);

            return node->val;
        }
    }
    
    void put(int key, int value) {
        
        if (dict.count(key) > 0) {
            // update
            Node* node = dict[key];
            node->val = value;
            erase(node);
            insertHead(node);
        } else {
            // insert
            if (dict.size() >= cacheSize) {
                // remove last node
                int lastKey = tail->prev->key;
                Node* lastNode = dict[lastKey];
                dict.erase(lastKey);
                erase(lastNode);
            }
            Node* node = new Node(key, value, head, head->next);
            insertHead(node);
            dict[key] = node;
        }
    }

    void erase(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertHead(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
private:
    unordered_map<int, Node*> dict;
    Node* head = nullptr;
    Node* tail = nullptr;
    int cacheSize = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */