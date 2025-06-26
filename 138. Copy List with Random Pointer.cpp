Node* copyRandomList(Node* head) {
        //to create a mapping for old nodes to new nodes
        unordered_map<Node*, Node*> oldToCopy;
        
        oldToCopy[nullptr] = nullptr; 
        /*
        If cur->next or cur->random is NULL, we’d be doing:
        copy->random = oldToCopy[NULL];  // must safely return NULL
        Without explicitly adding oldToCopy[NULL] = NULL, 
        this lookup would result in undefined behavior or a crash.
        */
        
        Node* curr = head; //creating and pointing the current on head

        while(curr != nullptr) {
            Node* copy = new Node(curr->val); //creating a new node
            oldToCopy[curr] = copy; // adding the pointer to the new node in map
            curr = curr->next; //moving the pointer of the old list
        }

        curr = head; //setting the current back to head
        while(curr != nullptr) {
            //taking the pointer to the newly created nodes
            //and then giving them their next and random pointers
            Node* copy = oldToCopy[curr];
            copy->next = oldToCopy[curr->next]; 
            copy->random = oldToCopy[curr->random];
            curr = curr->next; //moving the curr in the old list
        }

        return oldToCopy[head]; //returning the head of the new list
    }