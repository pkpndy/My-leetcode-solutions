class Solution {
public:
    static bool comp(const vector<int> inter1, vector<int> inter2) {
        return inter1[1]<inter2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);

        int meetings=0;
        int lastEndTime=INT_MIN;
        for(auto it: intervals) {
            int s=it[0];
            int e=it[1];
            if(s>=lastEndTime) {
                meetings++;
                lastEndTime=e;
            }
        }

        //here it was asked to count the number of overlapping intervals that need to be removed
        return n-meetings;
    }
};