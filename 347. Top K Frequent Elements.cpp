class Solution {
public:
    using Pr = pair<int, int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        vector<int> vec;

        for(int it: nums) {
            mpp[it]++;
        }

        priority_queue<Pr, vector<Pr>, greater<Pr>> pq;

        for(auto const& it: mpp) { //use it like this as this will suit even for -ve elements in nums
            pq.push({it.second, it.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        while(!pq.empty()) {
            vec.push_back(pq.top().second);
            pq.pop();
        }
        return vec;
    }
};