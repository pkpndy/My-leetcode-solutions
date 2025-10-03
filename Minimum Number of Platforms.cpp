int calculateMinPatforms(int at[], int dt[], int n) {
    int minPlatforms = 0;
    int platforms=0;
    int i=0, j=0; //we will keep two pointers i for arrival and j for departure
    sort(at, at+n);
    sort(dt, dt+n);
    while(i<n && j<n) {
        if(at[i]<=dt[j]) {// train arrives before the earliest departure
            platforms++;
            i++;
        } else {// train departs
            platforms--;
            j++;
        }
        minPlatforms = max(platforms, minPlatforms);
    }
    return minPlatforms;
}