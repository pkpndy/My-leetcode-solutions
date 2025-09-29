#include<algorithm>

bool comparator(const vector<int>& jobs1, const vector<int>& jobs2)
{
    return jobs1[2]>jobs2[2]; //sorting in descending order of profits
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comparator);
    int maxDeadline=-1; //
    for(auto it: jobs) {
        maxDeadline = max(maxDeadline, it[1]);
    }
    vector<int> jobDays(maxDeadline+1, -1);
    int maxProfit=0; //maxProfit we can get after doing all the jobs under deadline
    int jobsDone=0; //total number of jobs finished
    for(auto it: jobs) { //iterate the jobs vector
        //to start from deadline and trying to do it before if any job is 
        //already being done on that day
        for(int j=it[1]; j>0; j--) { //it[1] has the deadline for any job
            if(jobDays[j] == -1) { //if any day is vacant for job to be done
                jobsDone++; //increase the jobs done count
                jobDays[j]=it[0]; //store the job id on that day
                maxProfit += it[2]; //it[2] has the profit of any particular job
                break; //break out of the loop and go for next job
            }
        }
    }

    return {jobsDone, maxProfit};
}