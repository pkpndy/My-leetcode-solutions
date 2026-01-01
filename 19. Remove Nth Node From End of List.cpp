class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases (like deleting the head)
        // All the nodes are just before the head in the start
        ListNode* dummy = new ListNode(0, head);
        ListNode* ahead=dummy;
        ListNode* behind=dummy;
        // Move ahead n+1 steps so the gap between ahead and behind is n
        for(int i=0; i<=n; i++) {
            ahead=ahead->next;
        }
        // Move both pointers until ahead crosses the linkedlist
        while(ahead != nullptr) {
            behind=behind->next;
            ahead=ahead->next;
        }
        
        // Now behind is just before the node to delete
        ListNode* nodeToDelete = behind->next;
        behind->next=behind->next->next;
        delete nodeToDelete;

        return dummy->next; // return new head (in case head was deleted)
    }
};