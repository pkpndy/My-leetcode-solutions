// class Solution {
// private:
//     void givePer(vector<int>& nums, vector<int> visited, vector<int> ds, vector<vector<int>>& ans)
//     {
//         if(ds.size() == nums.size()) { //base case : we built complete permutation
//             ans.push_back(ds);
//             return;
//         }

//         for(int i=0; i<nums.size(); i++) { //loop to check the unvisited nums
//             if(!visited[i]) { //only visit the unvisited numbers
//                 ds.push_back(nums[i]); //add to current permutation
//                 visited[i] = 1; //mark visited so others can be chosen
//                 givePer(nums, visited, ds, ans); // call the function again for other numbers
//                 visited[i] = 0; //backtrack mark unvisited
//                 ds.pop_back(); //backtrack remove from the permutation
//             }
//         }
//     }
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> ds;
//         vector<int> visited(nums.size(), 0); //to mark the nums that are visited
//         givePer(nums, visited, ds, ans);

//         return ans;
//     }
// };

//this solution below takes no extra space as it uses swapping
class Solution {
private:
    void givePer(int idx, vector<int>& nums, vector<vector<int>>& ans)
    {
        if(idx == nums.size()) { //since we move index and swap it with all the numbers ahead
            ans.push_back(nums); //when our index has traversesd the entire nums we get our combo
            return;
        }

        //index will be our current position while i will swap index element with ahead elements
        for(int i = idx; i<nums.size(); i++) { //i from idx till end
            swap(nums[idx], nums[i]); //swap the current index element with each number ahead of it
            givePer(idx+1, nums, ans); //recurse for next position
            swap(nums[idx], nums[i]); //backtrack by swapping back
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        givePer(0, nums, ans); //we will use swapping with moving index

        return ans;
    }
};

/*

Take/Not Take (idx+1):

We're making a decision about element at position idx
Next call decides about element at position idx+1
Linear progression through array

*/
