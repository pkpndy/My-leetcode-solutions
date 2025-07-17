class Solution {
public:
    //TC:O(mXn) SC:O(nXm) + O(n)
    //In the brute force solution by mistake I drew recursion tree using values
    //There is overlapping subproblems if the same position(indexs) is checked again
    int triMin(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i == triangle.size()-1) { //if i reaches the last row
            return triangle[i][j]; //return the value of the element
        }

        if(dp[i][j] != -1)  return dp[i][j];

        int down = triangle[i][j] + triMin(i+1, j, triangle, dp); //add the element and go down
        int diagonal = triangle[i][j] + triMin(i+1, j+1, triangle, dp); //add the element and go diagonal

        return dp[i][j] = min(down, diagonal); //return the minimum of going down or diagonal
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp; //don't give the size to dp vector as it will places zeros
        for(int i=0; i<triangle.size(); i++) {
            dp.push_back(vector<int>(i+1, -1));
        }
        return triMin(0,0,triangle, dp); //we start from the first element
    }

    /*
    //tabulated solution TC:O(nXm) SC:O(nXm)
    //we will go from base case(of the recursive approach) to final solution
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        //initialise the dp vector by giving size or else it will give 
        //runtime-error: applying non-zero offset 72 to null pointer
        //or else use push_back if not initializing
        vector<vector<int>> dp(n, vector<int> (n));
    
        for(int j=0; j<triangle[n-1].size(); j++) { //fill values in the last row
            dp[n-1][j] = triangle[n-1][j];
        }

        //going from last to first row helps as we don't need to take case of the edge cases
        for(int i=n-2; i>=0; i--) { //starting from second last row, as the last row is our base case
            for(int j=0; j<triangle[i].size(); j++) { //numberr of columns in that row
                int down = triangle[i][j] + dp[i+1][j]; //going up, then below row will help
                int diagonal = triangle[i][j] + dp[i+1][j+1]; ////going diagonally up, then below row will help
                dp[i][j] = min(down, diagonal); //assigning the minimum of either paths
            }
        }

        return dp[0][0]; //the top most position will have the minimum
    }
    */

    /*
    //space optimized solution TC:O(nXm) SC:O(1)
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> belowRow;
    
        for(int j=0; j<triangle[n-1].size(); j++) { //fill values in the below row
            belowRow.push_back(triangle[n-1][j]);
        }

        //going from last to first row helps as we don't need to take case of the edge cases
        for(int i=n-2; i>=0; i--) { //starting from second last row, as the last row is our base case
            vector<int> curr(n); //current row, that will become previous(belowRow) row
            for(int j=0; j<triangle[i].size(); j++) { //number of columns in that row
                int down = triangle[i][j] + belowRow[j]; //going up, then below row will help
                int diagonal = triangle[i][j] + belowRow[j+1]; ////going diagonally up, then below row will help
                curr[j] = min(down, diagonal); //assigning the minimum of either paths
            }
            belowRow = curr; //assign the current row to previous and move to above row
        }

        return belowRow[0]; //the top most position will have the minimum
    }
    */

};