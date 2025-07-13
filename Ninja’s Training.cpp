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
