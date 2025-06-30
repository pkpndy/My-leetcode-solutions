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
        ListNode* tail = &dummy; // this tail will help in creating our sorted merged list

        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1; //add the node to our result list
                l1=l1->next; //move the l1 pointer
            } else {
                tail->next = l2; //add the node to our result list
                l2=l2->next; //move the l2 pointer
            }
            tail=tail->next; //move the pointer in our result list
        }
        if(l1) {
            tail->next=l1; //add the remaining list to our result
        }
        if(l2) {
            tail->next=l2; //add the remaining list to our result
        }
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())   return nullptr; //if there are no lists

        while(lists.size() > 1) { //keep on sorting and merging till there is only one list
            // and that one list will be the final one sorted and merged list
            vector<ListNode*> mergedLists;
            for(int i=0; i<lists.size(); i+=2) { //taking two lists in each iteration
                ListNode* l1 = lists[i]; //taking the first list in this iteration
                // checking if the next to current list there is list or not
                //(odd number of lists case)
                ListNode* l2 = i+1 < lists.size() ? lists[i+1] : nullptr;
                mergedLists.push_back(mergeList(l1, l2)); //pushing the result of the merging
            }
            lists = mergedLists; // so that we dont use extra space
        }
        return lists[0]; //since there will be only one final merged list
    }
};