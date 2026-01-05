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

        while(prev->next && prev->next->next) { //loop will run till pair of nodes is left
            ListNode* first = prev->next; //first node
            ListNode* second = first->next; //second node

            //swap
            first->next=second->next; //connect first node to the next node of the second
            second->next=first;  //connect second node to the first so that it goes back
            prev->next = second; //connect the prev node to this newly moved second node

            //move prev to the previous of next pair to be reversed
            prev=first; //since first node moved ahead (that was earlier the place of second)
        }
        return dummy.next;
    }
};