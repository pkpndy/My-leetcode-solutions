#include<unordered_map>

//prefix sum approach
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();
    int longest=0;
    unordered_map<int, int> mpp;
    //for the case where we have a subarray starting from index 0 
    //means the entire array summed up becomes equal to k
    mpp[0] = -1;

    /*
    dry run without the base case
    array: [1, 2, 3], k = 6
    prefix sums: [1, 3, 6]
    at i = 2: pref[2] = 6, equals k.
    with the base case {0:-1}, we see pref[2] - k = 0, found at -1, so subarray [0..2] length = 3.

    if we don’t have 0:-1, the map won’t contain 0, so we miss it.
    answer would wrongly be 0 instead of 3.
    */

    int pfx=0;
    for(int i=0; i<n; i++) {
        pfx += a[i];
        if(pfx == k) {
            longest = max(longest, i+1);
        }

        auto it = mpp.find(pfx-k);
        if(it != mpp.end()) {
            longest = max(longest, i-(it->second));
        }
        if(mpp.find(pfx) == mpp.end()) { //this is for the case where there are zeros in the array in between
            mpp.insert({pfx, i});
        }
    }

    return longest;
}

//two pointer approach only applicable for non-negative numbers
//the TC:O(2N) because we are only taking the right and left till the end once, SC:O(1)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();
    int maxLen=0;
    int right=0, left=0;
    //long long because sum might get large
    long long sum=0; //we start with the first element in the sub array
    
    while(right < n) {
        sum += a[right]; //expand window to the right

        // shrink while sum is too large
        while(left<=right && sum>k) {
            sum -= a[left];
            left++;
        }
        //check if window sum equals k
        if(sum==k) {
            maxLen = max(maxLen, (right-left)+1);
        }
        right++;
    }

    return maxLen;
}