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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode dummy1(0, head);
        ListNode dummy2(0, head->next);

        ListNode* odd = dummy1.next;
        ListNode* even = dummy2.next;

        while(even && even->next) {
            odd->next=even->next;
            even->next= (even->next) ? even->next->next : nullptr;
            odd=odd->next;
            even=even->next;
        }

        odd->next = dummy2.next; //odd wale ke last ko even ke first se conenct kr do

        return dummy1.next;
    }
};