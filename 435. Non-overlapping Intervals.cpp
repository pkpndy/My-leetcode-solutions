class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <=1)    return 0;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int n = intervals.size();
        int i=0, j=i+1;
        while(i<n && j<n) {
            if(intervals[j][0] < intervals[i][1]) {
                count++;
            } else {
                i=j;
            }
            j++;
        }

        return count;
    }
};