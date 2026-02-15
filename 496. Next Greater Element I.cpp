class Solution {
public:
    // use monotonic stack
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n2 = nums2.size();
        if(nums1.empty() || nums2.empty())    return {};

        for(int i=n2-1; i>=0; i--) {
            while(!st.empty() && nums2[i]>st.top()) {
                st.pop();
            }
            auto it = find(nums1.begin(), nums1.end(), nums2[i]);
            if(it != nums1.end()) {
                int idx = it - nums1.begin();
                nums1[idx] = st.empty() ? -1 : st.top();
            }
            st.push(nums2[i]);
        }
        return nums1;
    }
};