void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        //finding the middle of the linked list
        //the slow pointer will reach the middle
        while(fast != nullptr && fast->next != nullptr) {
        //we use && because we want the loop to continue only when both fast and fast->next are valid
            slow = slow->next;
            fast = fast->next->next;
        }
    
        ListNode* second = slow->next; // the second linked list starts just after slow
        slow->next = nullptr; //breaking the list from the middle to make it two

        //reversing the second linked list
        ListNode* prev = nullptr;
        while(second != nullptr) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        //merging the two lists
        ListNode* first = head; //pointer at the first head
        second = prev; //pointer at the second head
        while(second != nullptr) {
            ListNode* tmp1 = first->next; //giving a pointer to move first
            ListNode* tmp2 = second->next; //giving a pointer to move second
            first->next = second; //making second as first next
            second->next = tmp1; // making first next as the second next
            first = tmp1; //moving first ahead
            second = tmp2; //moving second ahead
        }

    }