bool comp(const pair<pair<int, int>, int> meet1, 
            const pair<pair<int, int>, int> meet2) {
    return meet1.first.second < meet2.first.second;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    //position can be stored in case the order of the meetings is asked
    vector<pair<pair<int, int>, int>> meets(n); //{{start, end}, position}
    
    for(int i=0; i<n; i++) {
        int s = start[i];
        int e = end[i];
        meets[i].first.first = s;
        meets[i].first.second = e;
        meets[i].second = i;
    }

    //sort them according to ascending endTime
    sort(meets.begin(), meets.end(), comp);

    int meetings=0; //store the number of meetings possible
    int lastMeetEnd=0; //the end time of last held meeting
    for(auto it: meets) {
        int s = it.first.first;
        int e = it.first.second;
        //if the starting of current meeting is after the previous meeting got over
        if(s>lastMeetEnd) {
            meetings++; //increase the number of meetings held
            lastMeetEnd=e; //store the end time of this meeting
        }
    }

    return meetings;
}