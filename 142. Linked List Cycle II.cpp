/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr)   return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast && fast->next) { //check if fast or fast->next is nullptr then there's no cycle
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return nullptr; //if fast or fast->next is nullptr then there's no cycle

        ListNode* slow2=head;
        while (slow != slow2) { //move till slow and slow2 don't meet
            slow = slow->next;
            slow2 = slow2->next;
        }
        return slow; //return slow once they meet
    }
};