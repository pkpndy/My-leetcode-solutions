class Solution {
public:
    //recursive solution takes TC:O(3^n X 3^n) SC:O(n)
    //memoized solution takes TC:O(nXmXm)X9 SC:O(nXmXm) + O(n)
    int maxCherry(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int r = grid.size();
        int c = grid[0].size();
        if(j1<0 || j2<0 || j1>=c || j2>=c)  return -1e8; //out of bounds doesn't contribute to the ans
        if(i==r-1) { //if reached last row
            if(j1==j2)  return grid[i][j1]; //if both reached at the same position, then one picks
            else    return grid[i][j1]+grid[i][j2]; //if both diff position, both pick
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e8; //negative smallest number (that wont cause overflow for int)
        for(int dj1=-1; dj1<=1; dj1++) { //the movements for robot1
            for(int dj2=-1; dj2<=1; dj2++) { //the movements for robot2 for each movement of robot1
                int value = 0; //to store value given by cherries

                //Since value = current position value + f(next position);
                //these are for current position
                if(j1==j2)  value = grid[i][j1]; //if both reach at the same position
                else    value = grid[i][j1] + grid[i][j2]; //if both are at different position
                
                //these are for f(next position)
                //move to next row; move j1 by adding -1, 0, 1; j2 by adding -1, 0, 1
                value += maxCherry(i+1, j1+dj1, j2+dj2, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        //we have 3 things that are gonna determine the function calls, hence 3d vector
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        //maxCherry(i, j1, j2, grid, dp);
        return maxCherry(0,0,c-1, grid, dp);
    }

    /*
    //tabulated solution
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //we have 3 things that are gonna determine the function calls, hence 3d vector
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        
        for(int j1=0; j1<m; j1++) {
            for(int j2=0; j2<m; j2++) {
                if(j1==j2)  dp[n-1][j1][j2] = grid[n-1][j1];
                else    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i=n-2; i>=0; i--) {
            for(int j1=0; j1<m; j1++) {
                for(int j2=0; j2<m; j2++) {
                    int maxi = -1e8;
                    for(int dj1=-1; dj1<=1; dj1++) {
                        for(int dj2=-1; dj2<=1; dj2++) {
                            int value = 0;
                            if(j1==j2)  value = grid[i][j1];
                            else    value = grid[i][j1] + grid[i][j2]; 
                            if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m)
                                value += dp[i+1][j1+dj1][j2+dj2];
                            else    
                                value = -1e8;
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m-1];
    }
    */

    /*
    //we already saw that for 
    //1D -> two variables
    //2D -> 1D array
    //3D -> 2D array
    //space optimised solution
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> front(m, vector<int>(m));
        vector<vector<int>> curr(m, vector<int>(m));
        
        for(int j1=0; j1<m; j1++) {
            for(int j2=0; j2<m; j2++) {
                if(j1==j2)  front[j1][j2] = grid[n-1][j1];
                else    front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i=n-2; i>=0; i--) {
            for(int j1=0; j1<m; j1++) {
                for(int j2=0; j2<m; j2++) {
                    int maxi = -1e8;
                    for(int dj1=-1; dj1<=1; dj1++) {
                        for(int dj2=-1; dj2<=1; dj2++) {
                            int value = 0;
                            if(j1==j2)  value = grid[i][j1];
                            else    value = grid[i][j1] + grid[i][j2]; 
                            if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m)
                                value += front[j1+dj1][j2+dj2];
                            else    
                                value = -1e8;
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }

        return front[0][m-1];
    }
    */
};