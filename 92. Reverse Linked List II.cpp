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
        ListNode* temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
      }

      return dummy.next;
    }
};