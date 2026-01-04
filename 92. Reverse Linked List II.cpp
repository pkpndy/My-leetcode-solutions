/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right)  return head;

        // Dummy node to handle edge cases (like left = 1)
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        // 1. Move prev to the node just before 'left'
        for(int i=1; i<left; i++) {
          prev = prev->next;
        }

        // 2. Reverse the sublist from left to right
        //here we are reversing one node at a time
        //the curr will keep the track of the current node to be reversed
        ListNode* curr = prev->next; // first node of sublist
        for(int i=0; i<right-left; i++) {
          ListNode* temp = curr->next;  //we point to the next node that will go left in this iteration
          curr->next = temp->next;  //we shift current node ahead once in each iteration
          temp->next = prev->next;  //we move the node just ahead to the back(left)
          prev->next = temp;  //we point the moved node by the prev as next
        }

        return dummy.next;
    }
};