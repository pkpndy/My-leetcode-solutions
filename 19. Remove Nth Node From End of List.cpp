ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr && n == 1)   return nullptr; //edge case

        ListNode* prev = nullptr; // to track previous
        ListNode* curr = head; // current node
        ListNode* ahead = head; // to track the distance from the last node
        int i=1;
        while(i != n) {
            ahead = ahead->next; //sending ahead to the nth node
            i++;
        }
        while(ahead->next != nullptr) { // moving the pointers to the desired node to be removed
            prev = curr;
            curr = curr->next;
            ahead = ahead->next;
        }
        if(prev == nullptr) head = curr->next; // if the node to be removed is the first node
        else    prev->next = curr->next; // else it is some node in the middle

        return head;
    }