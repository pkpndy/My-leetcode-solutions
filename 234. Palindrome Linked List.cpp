class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* ptr=head;
        while(ptr!=nullptr) {
            st.push(ptr->val);
            ptr=ptr->next;
        }
        ListNode* ptr2=head;
        while(ptr2) {
            if(ptr2->val != st.top())  return false;
            st.pop();
            ptr2=ptr2->next;
        }
        return true;
    }
};

class Solution {
public:
    ListNode* front;

    bool curse(ListNode* node) {
        if(!node)   return true;
        
        if(!curse(node->next))  return false;

        if(node->val != front->val) return false;
        front=front->next;
        return true;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* end=head;
        front=head;
        if(!curse(end)) return false;
        return true;
    }
};

bool isPalindrome(ListNode* head) {
        if(!head || !head->next)    return true;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast)    slow=slow->next; //if the length of the list is odd then we ignore the middle node

        ListNode* prev = nullptr;
        while(slow) {
            ListNode* temp = slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }

        ListNode* first = head;
        ListNode* second = prev;
        while(second) {
            if(first->val != second->val) {
                return false;
            }
            first=first->next;
            second=second->next;
        }

        return true;
}