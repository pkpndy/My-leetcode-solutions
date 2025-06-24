ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0); //dummy node to return the head later
        ListNode* node = &dummy; //node pointer to point to the result list

        while(list1 && list2) { // till none of them is nullptr
            if(list1->val < list2->val) {
                node->next = list1; //adding list1 node to the result list
                list1 = list1->next; //moving the list1 pointer forward
            } else {
                node->next = list2; //adding list2 node to the result list
                list2 = list2->next; //moving the list2 pointer forward
            }
            node = node->next; //moving the resulting node pointer forward
        }

        if(list1) { //if list1 nodes are left
            node->next = list1; //simply add the nodes to the result
        } else {
            node->next = list2; //else add the list2 nodes to the result
        }

        return dummy.next; // the list starts from the next of the dummy
    }