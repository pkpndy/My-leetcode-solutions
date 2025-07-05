class Solution {
private:
void giveC(int i, vector<vector<int>>& ans, vector<int> ds, vector<int>& candidates, int target)
{
    if(i == candidates.size()) { //if reached last index then return
        if(target == 0) { //if last index return and target became 0
            ans.push_back(ds); //that means we got a satisfying combination so push it
        }
        return;
    }
    //the three lines in this are for pick
    if(candidates[i] <=target) { //if the number we reached is smaller than our target right now
        ds.push_back(candidates[i]); //then push the number to the current data structure
        giveC(i, ans, ds, candidates, target-candidates[i]); //take and call again
        ds.pop_back(); // now before going remove the number we added (backtrack)
    }
    //this one line is for not pick
    giveC(i+1, ans, ds, candidates, target); //not take and move ahead
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        giveC(0, ans, ds, candidates, target);
        return ans;
    }
};