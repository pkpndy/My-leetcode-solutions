class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        //pq defaults to descending order, for ascending order do this
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]); //first we push the new element to its desired position
            if(pq.size()>k) { //then we check if the size of pq increased
                pq.pop();
            }
        }
        return pq.top();
    }
};