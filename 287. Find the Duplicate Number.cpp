int findDuplicate(vector<int>& nums) {
        //we use Floyd’s Cycle Detection Algorithm (Tortoise and Hare) 
        //to find the entry point of the cycle, which is the duplicate.
        int slow=0, fast=0;
        //the array here basically creates a linked list
        while(true) {
            slow = nums[slow]; //slow moves 1 step
            fast = nums[nums[fast]]; //fast moves 2 steps
            if(slow == fast)    break; //collision point
        }

        int slow2=0; //another slow pointer at zero
        while(true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if(slow==slow2) return slow; //both will collide at the point of cycle
        }
    }