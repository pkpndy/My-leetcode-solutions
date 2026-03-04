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

//upar wale ke alwa ye bhi ek solution hai
class Solution {
public:
    void cs(int i, vector<int>& candi, int tar, vector<int>& ds, vector<vector<int>>& result) {
        if(tar==0) {
            result.push_back(ds);
            return;
        }

        for(int j=i; j<candi.size(); j++) {
            if(candi[j] > tar) break;
            ds.push_back(candi[j]);
            cs(j,candi, tar-candi[j], ds, result);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> ds;

        cs(0, candidates, target, ds, result);

        return result;
    }
};