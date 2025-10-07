class Solution {
public:
    //naive solution
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n), right(n);
        vector<int> result(n);
        int answer=0;
        left[0]=1;
        right[n-1]=1;

        for(int i=1; i<n; i++) {
            if(ratings[i] > ratings[i-1]) {
                left[i] = left[i-1] + 1;
            } else {
                left[i]=1;
            }
        }

        for(int i=n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                right[i] = right[i+1] + 1;
            } else {
                right[i] = 1;
            }
        }

        for(int i=0; i<n; i++) {
            result[i] = max(left[i], right[i]);
            answer += result[i];
        }

        return answer;
    }

    //slope approach
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum=1;
        int peak, down;
        int i=1;
        while(i<n) {
            if(ratings[i] == ratings[i-1]) { //when the slope is flat
                sum += 1;
                i++;
                continue;
            }
            //when there is increasing slope
            peak=1;
            while(i<n && ratings[i] > ratings[i-1]) {
                peak += 1;
                sum += peak;
                i++;
            }
            //when there is decreasing slope
            down=1;
            while(i<n && ratings[i] < ratings[i-1]) {
                sum += down;
                down += 1;
                i++;
            }
            //if the decreasing slop gave larger max,
            //since decreasing slope is for right to left direction slope check
            //this means the same peak will have max from the right to left direction
            if(down > peak) {
                sum += down-peak;
            }
        }
        return sum;
    }
};