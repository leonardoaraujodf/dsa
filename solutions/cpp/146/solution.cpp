class LRUCache {
public:
    /**
     * @brief Double linked list.
     */
    struct ListNode {
        int k;
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode(int key, int value) : k(key), val(value), next(nullptr), prev(nullptr) {}
    };

    ListNode *head;
    ListNode *tail;
    unordered_map<int, ListNode*> localMap;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (localMap.find(key) == localMap.end()) {
            return -1;
        }

        ListNode *node = localMap[key];
        removeNode(node);
        addNode(node);
        return node->val;
    }

    void put(int key, int value) {
        // Check if key already exists in the cache
        if (localMap.find(key) != localMap.end()) {
            // cout << "key " << key << "already exists." << endl;
            // Get node from map
            ListNode *node = localMap[key];
            // Update to its new value
            node->val = value;
            removeNode(node);
            addNode(node);
            return;
        }

        // Check for capacity
        if (localMap.size() == capacity) {
            //cout << "Maximum capacity reached!" << endl;
            //cout << "Head: " << head->val << endl;
            //cout << "Tail: " << tail->val << endl;
            ListNode *nodeToDelete = head->next;
            removeNode(nodeToDelete);
            localMap.erase(nodeToDelete->k);
            delete nodeToDelete;
        }

        //cout << "Key " << key << " does not exist and will be added." << endl;
        ListNode *node = new ListNode(key, value);
        addNode(node);
        localMap[key] = node;
    }

    void removeNode(ListNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNode(ListNode *node) {
        ListNode *previousEnd = tail->prev;
        previousEnd->next = node;
        node->prev = previousEnd;
        node->next = tail;
        tail->prev = node;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */