class Solution {
public:
    using Pr = pair<int, pair<int, int>>;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Pr> pq;
        vector<vector<int>> ans;
        
        for(int i=0; i<min((int)nums1.size(), k); i++) {
            for(int j=0; j<min((int)nums2.size(), k); j++) {
                int sum = nums1[i] + nums2[j];

                if (pq.size() < k) {
                    pq.push({sum, {nums1[i], nums2[j]}});
                } else if (sum < pq.top().first) {
                    // If this sum is smaller than the largest in our heap, swap them
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                } else {
                    // Since arrays are sorted, if nums1[i]+nums2[j] is too big,
                    // then nums1[i]+nums2[j+1] will definitely be too big.
                    break;
                }
            }
        }

        while(!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};