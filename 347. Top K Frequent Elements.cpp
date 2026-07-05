class Solution {
public:
    using Pr = pair<int, int>; //creating an alias for pair
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp; //create a map that will store the frequency of each number
        vector<int> result;
        for(int it: nums) {
            mpp[it]++;
        }

        priority_queue<Pr, vector<Pr>> pq; //max-heap that will store the max numbers at the top
        for(auto &it: mpp) {
            pq.push({it.second, it.first}); //push in the pq according to the frequency, so the highest frequency stays at the top
        }

        while(k>0) {
            auto curr = pq.top().second; //bring the actual number since they are sorted according to their frequency
            result.push_back(curr);
            pq.pop();
            k--;
        }

        return result;
    }
};
