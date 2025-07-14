/*
Problem statement
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
*/

//this is the memoized solution TC:O(N) SC:O(N) + O(N)
int maxP(int day, int lastTask, vector<vector<int>>& points, vector<vector<int>>& dp) {
    if(day == 0) { //if we reach day 0
        int maxiE = 0;
        for(int i=0; i<3; i++) { //we are trying all the tasks, max will be choosen
            if(i != lastTask) { //if this task wasn't done yesterday
                //choose the max points task for today (day 0)
                maxiE = max(maxiE, points[day][i]);
            }
        }
        return maxiE; //return the max points
    }

    //if on this [day] this [task] max was calculated return it
    if(dp[day][lastTask] != -1) return dp[day][lastTask]; 
    
    int maxi = 0;
    for(int i=0; i<3; i++) { //we are trying all the tasks, max will be choosen
        if(i != lastTask) { //if this task wasn't done yesterday
            // accumulate the previous days max points and add today's points
            int currMaxPoints = points[day][i] + maxP(day-1, i, points, dp);
            maxi = max(maxi, currMaxPoints); //choose the max points
        }
    }
    //store the max for [today][lastTask] and also return the value
    return dp[day][lastTask] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    //we will use a dp vector where each index is a day and
    //inside there each position in vector is a task,
    //and the values are the max points for that task on that day
    vector<vector<int>> dp(n, vector<int> (4, -1));

    //chose ending day because we are using top-down approach
    //we call the maxPoints(ending day, task done, points vector)
    return maxP(n-1, 3, points, dp);
}

/*
//this is tabulation solution TC:O(N) SC:O(N)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int> (4, 0));

    //in the base case we had these results, so we need to generate them
    //the result of doing any task was 
    //the max from the other two tasks from the previous day
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][2], points[0][0]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1; day<n; day++) { //we start from day 1
        for(int lastTask=0; lastTask<4; lastTask++) { //with each day we had a last task 
            //we are trying to store the values in the table in each iteration
            dp[day][lastTask] = 0;
            for(int task=0; task<3; task++) { //we tried all the tasks
                if(task != lastTask) { //we check if this task wasn't done yesterday
                    //since the table is storing the max points 
                    //that can be obtained for that task on that day
                    dp[day][lastTask] = max(dp[day][lastTask], points[day][task] + dp[day-1][task]);
                }
            }
            
        }
    }
    return dp[n-1][3]; //the last day the last activity will store the maximum
}
*/

/*
//this is space optimised solution
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);

    //day 0 (base case)
    prev[0] = max(points[0][1], points[0][2]); //cant do activity 0 (which means 0 was the lastTask)
    prev[1] = max(points[0][2], points[0][0]); //cant do activity 1 (which means 1 was the lastTask)
    prev[2] = max(points[0][0], points[0][1]); //cant do activity 2 (which means 2 was the lastTask)
    prev[3] = max(points[0][0], max(points[0][1], points[0][2])); //no tasks done 

    for(int day=1; day<n; day++) {
        vector<int> temp(4, 0); //we calculate max points for each task for a day
        for(int lastTask=0; lastTask<4; lastTask++) {
            temp[lastTask] = 0;
            for(int task=0; task<3; task++) {
                if(task != lastTask) {
                    //we always calculate the max points for lastTask
                    //then we choose which activity from the previous ones gave max
                    temp[lastTask] = max(temp[lastTask], points[day][task] + prev[task]);
                    
                    // points = [[1,2,5], [3,1,1], [3,3,3]]
                    // temp[0]: can't do activity 0 on day 1 (means did task 0 on day 0)
                    // Can do activity 1: points[1][1] + prev[1] = 1 + 5 = 6
                    // Can do activity 2: points[1][2] + prev[2] = 1 + 2 = 3
                    // temp[0] = max(6, 3) = 6;
                }
            }
        }
        prev = temp; //we store todays maxpoints as previous day for next iteration
    }
    return prev[3]; //the last day the last activity will store the maximum
}
*/