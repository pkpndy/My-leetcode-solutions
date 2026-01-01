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
    //in this approach we we try to bring both the pointers at the same level in both the lists
    //by moving forward the pointer of whichever list is longer and then we check where they meet 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode *pa = headA;
        ListNode *pb = headB;

        int ll1=0, ll2=0; //get the length of both the lists
        while(pa != nullptr) {
            pa=pa->next;
            ll1++;
        }
        while(pb != nullptr) {
            pb=pb->next;
            ll2++;
        }

        pa=headA;
        pb=headB;
        int diff=0; //store the difference in their lengths
        //move forward by the difference whichever is longer
        if(ll2>ll1) {
            diff=ll2-ll1;
            for(int i=1; i<=diff; i++) pb=pb->next;
        } else {
            diff=ll1-ll2;
            for(int i=1; i<=diff; i++) pa=pa->next;
        }
        
        while(pa != nullptr) {
            if(pa==pb)  return pa; //if they meet return the node
            pa=pa->next;
            pb=pb->next;
        }

        return nullptr;
    }
};