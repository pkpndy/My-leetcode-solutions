vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> output(n-k+1); //the output array
        deque<int> q; //dequeue to push and pop indexes
        int l=0, r=0;

        while(r<n) {
            //removing indexes of all the smaller numbers than the current number 
            while(!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r); // pushing current number index

            // if the index in the queue is less than l(window size) remove it
            if(l > q.front()) {
                q.pop_front();
            }

            //if we have atleast k elements in the window
            if(r+1 >= k) {
                output[l] = nums[q.front()];
                l++;
            }
            r++;
        }
        return output;
    }