class Solution {
public:
    void comb(int start, int n, int k, vector<int>& ans, vector<vector<int>>& result) {
        if(ans.size() == k) {
            result.push_back(ans);
            return;
        }

        // The loop starts from 'start' to ensure we never pick 
        // a number we've already passed (prevents [2,1] if we have [1,2])
        for (int i = start; i <= n; i++) {
            ans.push_back(i);          // Choose
            comb(i + 1, n, k, ans, result); // Recurse with i + 1
            ans.pop_back();            // Backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> ans;
        comb(1, n, k, ans, result);

        return result;
    }
};