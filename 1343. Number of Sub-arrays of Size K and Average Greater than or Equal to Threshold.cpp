class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count=0;
        int currSum=0;
        for(int i=0; i<k; i++) {
            currSum = currSum + arr[i];
        }
        int cleavage = currSum/k;
        if(cleavage>=threshold)  count++;

        for(int i=k; i<arr.size(); i++) {
            currSum = currSum + arr[i] - arr[i-k];
            cleavage = currSum/k;
            if(cleavage>=threshold)  count++;
        }
        return count;
    }
};
