class Solution {
public:
    //in this question think of the numbers inside the indexes as nodes and their connection
    //the edges are index->value
    int findDuplicate(vector<int>& nums) {
        //we use Floyd’s Cycle Detection Algorithm (Tortoise and Hare)
        //to find the entry point of the cycle, which is the duplicate.
        int slow=0, fast=0;
        while(true) { //since there always will be one repeated number, hence we can use while(true)
            slow=nums[slow];
            //since fast needs to move two steps, and from moving one connected to its connected node
            //we need to go to nums[nums[fast]]
            fast=nums[nums[fast]];
            if(slow==fast)  break; //if they meet that means there is a cycle in the linked list
        }

        int slow2=0; //now another pointer starts from the start of the linked list
        while(true) {
            slow=nums[slow]; //both move one node at a time
            slow2=nums[slow2];
            if(slow==slow2) return slow; //the node at which they meet is the  repeating number
        }
    }
};