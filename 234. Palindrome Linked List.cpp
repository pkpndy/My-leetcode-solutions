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