class Solution {
private:
    void giveC(int idx, vector<vector<int>>& ans, vector<int> ds, vector<int>& arr, int target)
    {
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
    
        for(int i=idx; i<arr.size(); i++) {
            if(idx < i && arr[i] == arr[i-1])   continue; //skip duplicates after first occurance 
            if(arr[i] > target) break; //break the loop as moving ahead has greater elements
            ds.push_back(arr[i]); // take
            giveC(i+1, ans, ds, arr, target-arr[i]); // recurse
            ds.pop_back(); // backtrack
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        sort(candidates.begin(), candidates.end()); //sort so that we can skip duplicates
        giveC(0, ans, ds, candidates, target);
        return ans;
    }
};