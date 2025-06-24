ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* first = nullptr;
        ListNode* second = head;
        ListNode* third = head->next;

        while(second != nullptr) {
            second->next = first;
            first = second;
            second = third;
            if(third != nullptr) {
                third = third->next;
            }
        }
        return first;
    }