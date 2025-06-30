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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head); //creating the first dummy node with head as next
        ListNode* groupPrev = dummy; //pointing the end of previous group at this dummy

        while(true) {
            ListNode* kth = getKth(groupPrev, k); //we want to get the kth after groupPrev node
            //this means in we want to get the kth node in our current group
            if(!kth) { //if the group end but we didn't find k in during any iteration
                break; //break as we don't need to reverse as this group doesn't have k nodes
            }
            ListNode* groupNext = kth->next; //next group starts after kth node
            //below nodes will be used for traversal
            ListNode* curr = groupPrev->next; //current group will start after previous group
            ListNode* prev = kth->next; //we point prev at the next group start
            while(curr != groupNext) { //we loop till curr doesn't reach next group start
                ListNode* tmp = curr->next;//we will change the next of the current,so we store it
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            ListNode* tmp = groupPrev->next; //pointing the tmp at the old head
            //kth node was the last node of the current group,
            //so it came at the first place after reversal
            groupPrev->next = kth; //we point kth node as the start of the current group
            // since old head was the first node of the group and
            //now it is the last node of the current group
            groupPrev = tmp; //we make it as the last node of the current group
            //which will become previous in the next iteration
        }
        return dummy->next;
    }

    ListNode* getKth(ListNode* curr, int k) {
        while(curr && k > 0) { //run the loop only if curr != nullptr && k > 0
            curr = curr->next; //move the pointer till kth node
            k--;
        }
        return curr; //return the pointer at which the current group ends
    }
};