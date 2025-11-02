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

class Solution {
public:
    //solution using stack
    void reorderList(ListNode* head) {
        if(!head || !head->next)    return;
        
        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Push second half nodes into stack
        stack<ListNode*> st;
        ListNode* curr = slow->next;
        slow->next = nullptr; //split the list
        while(curr) {
            st.push(curr);
            curr=curr->next;
        }

        // 3. Merge first half and reversed second half
        ListNode* start = head;
        while (!st.empty()) {
            ListNode* temp = st.top(); 
            st.pop();

            temp->next = start->next;
            start->next = temp;
            start = temp->next;
        }
    }
};

class Solution {
public:
    ListNode *first;    //global front pointer
    bool stop = false;

    void curse(ListNode* node) {
        if(!node)   return;
        curse(node->next); //go till end

        if(stop)    return; //if the pointers cross stop

        // connect current end node (node) with current front node (first)
        ListNode* firstNext=first->next;
        first->next=node;
        node->next=firstNext;
        first=firstNext; //move front pointer

        if(first==node || first->next==node) { //if they meet or cross stop linking
            node->next=nullptr;
            stop=true;
        }
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next)    return;
        ListNode* end=head;
        first=head;
        curse(end);
    }
};