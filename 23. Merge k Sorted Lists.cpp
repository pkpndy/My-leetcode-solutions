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
private:
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode dummy; //taking dummy node to handle head==nullptr edge case
        //so in the end if the head==nullptr then returning dummy.next will return nullptr
        ListNode* tail = &dummy;

        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1=l1->next;
            } else {
                tail->next = l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        if(l1) {
            tail->next=l1;
        }
        if(l2) {
            tail->next=l2;
        }
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())   return nullptr; //if there are no lists

        while(lists.size() > 1) { //if there are atleast two lists
            vector<ListNode*> mergedLists;
            for(int i=0; i<lists.size(); i+=2) { //taking two lists in each iteration
                ListNode* l1 = lists[i]; //taking the first list in this iteration
                
                // checking if the next to current list there is list or not
                //(odd number of lists case)
                ListNode* l2 = i+1 < lists.size() ? lists[i+1] : nullptr;
                mergedLists.push_back(mergeList(l1, l2)); //pushing the result of the merging
            }
            lists = mergedLists; //putting the merged list into the lists
        }
        return lists[0]; //since there will be only one final merged list
    }
};