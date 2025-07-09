class Solution {
public:
    int climbStairs(int n) {
        //this is the final space optimised solution
        int curr = 0; 
        int prev2 = 0; //there is 0 way to climb  the 0th stair
        int prev = 1; //there is one way to climb the 1st stair

        //n+1 because the final answer gets stored in the next position in dp array
        //for which we have optimised the space
        for(int i=2; i<=n+1; i++) {
            curr = prev2+prev;
            prev2 = prev;
            prev = curr;
        }
        
        //curr holds the final answer
        return curr;
    }
};