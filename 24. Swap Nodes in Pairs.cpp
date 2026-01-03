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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)    return head;

        ListNode dummy(0, head); //this is stack allocation and gets deleted
        ListNode* prev = &dummy;

        // if we want to use this then we need to `delete dummy;` 
        // just before returning bcoz this is heap allocated
        // ListNode* dummy = new ListNode(0, head);
        // ListNode* prev = dummy;

        while(prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            //swap
            first->next=second->next;
            second->next=first;
            prev->next = second;

            //move prev to the previous of next pair to be reversed
            prev=first;
        }
        return dummy.next;
    }
};