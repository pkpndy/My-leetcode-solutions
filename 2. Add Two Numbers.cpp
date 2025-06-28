ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //taking a dummy node to handle first node null edge case
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy; // to create the answer list

        int carry = 0;
        //run a loop till l1 or l2 is not finished or carry is not 0
        //the loop will keep running as long as any one of the condition is true 
        while(l1 != nullptr || l2 != nullptr || carry != 0) {
            int v1 = (l1 == nullptr) ? 0 : l1->val; //if l1 has finished then 0 will be given instead of null
            int v2 = (l2 == nullptr) ? 0 : l2->val; //if l2 has finished then 0 will be given instead of null
            int value = v1 + v2 + carry; //calculate the value
            carry = value / 10; //calculate the carry
            value = value % 10; //calculate and store only the ones place
            curr->next = new ListNode(value); //create new node and add the ones place
            curr = curr->next; //move the pointer of the result

            l1 = (l1 != nullptr) ? l1->next : nullptr; //move l1 pointer
            l2 = (l2 != nullptr) ? l2->next : nullptr; //move l2 pointer
        }
        ListNode* res = dummy->next; //our result head starts from dummy->next
        delete dummy;
        return res;
    }