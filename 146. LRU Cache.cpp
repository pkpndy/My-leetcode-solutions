class Node { //there are things that the node needs
    public:
        int key; 
        int val;
        Node* prev;
        Node* next;
        //This part is the initializer list, and it's the recommended way to
        //initialize class members in C++ (especially for classes 
        //with pointers, const members, or references).
        Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr){}
        /* Same as 
        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
        */
};

class LRUCache { //there are the things that our data structure needs
private:
    int cap; //capacity of the data structure
    //map of key to the node having the key and value to reach the node in o(1) time
    unordered_map<int, Node*> cache; 
    Node* left;
    Node* right;
public:
    LRUCache(int capacity) { //our data structure
        cap = capacity;
        cache.clear();
        left = new Node(0,0); //extreme left of the data structure
        right = new Node(0,0); //extreme right of the data structure
        //the data structure will start with left and right nodes used for recent 
        right->prev = left; 
        left->next = right;
    }

    void remove(Node* node) { //for removing the node from the data structure
        Node* prv = node->prev;
        Node* nxt = node->next;
        prv->next = nxt;
        nxt->prev = prv;
    }

    void insert(Node* node) { //for inserting the node in the data structure
        Node* prv = right->prev;
        prv->next = node;
        node->prev = prv;
        right->prev = node;
        node->next = right;
    }
    
    int get(int key) { //to get the value for a key in the data structure
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node); //remove the node
            insert(node); //re-insert the node to make it recent
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) { //to add a value to the data structure
        if(cache.find(key) != cache.end()) {
            remove(cache[key]); //remove the old value
        }
        Node* newNode = new Node(key, value); //create a new node with new value
        cache[key] = newNode; //add to the map
        insert(newNode); //add it to the data structure

        if(cache.size() > cap) { //if adding the new node crosses the DS capacity
            Node* lru = left->next;
            remove(lru); //remove from the data structure
            cache.erase(lru->key); //remove it's key from mapping
            delete lru; //delete the memory occupied by the node
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */