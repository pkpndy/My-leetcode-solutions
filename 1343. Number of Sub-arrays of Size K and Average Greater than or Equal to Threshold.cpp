class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count=0;
        int currSum=0;
        //window banao
        for(int i=0; i<k; i++) {
            currSum = currSum + arr[i];
        }
        int cleavage = currSum/k;
        if(cleavage>=threshold)  count++;

        //window badhao
        for(int i=k; i<arr.size(); i++) {
            currSum = currSum + arr[i] - arr[i-k]; // i-k will the number just went out of the window
            cleavage = currSum/k;
            if(cleavage>=threshold)  count++;
        }
        return count;
    }
};
