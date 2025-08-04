/*
You are given an array 'arr' of length 'n'.
Find the Longest Increasing Subsequence of the array.
A subsequence is a subset of an array achieved by removing some (possibly 0) elements without changing the order of the remaining elements.

Increasing subsequence means a subsequence in which all the elements are strictly increasing.

Longest increasing subsequence is an increasing subsequence that has the largest length possible.

Please note that there may be more than one LIS (Longest Increasing Subsequence) possible. Return any one of the valid sequences.

Example:
Input: ‘arr’ = [5, 6, 3, 4, 7, 6]

Output: LIS = [5, 6, 7] OR [3, 4, 7] OR [3, 4, 6]

Explanation: All these three subsequences are valid Longest Increasing Subsequences. Returning any of them is correct.
*/

//in this we are using algorithmic approach, which later helps in printing the LIS
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	//we will use hash array to store the index of the previous element of LIS
	vector<int> dp(n, 1), hash(n);
	for(int ind=0; ind<n; ind++) {
		//this will be usefult to end the storing of elements in the result array
		hash[ind] = ind;

		for(int prev=0; prev<ind; prev++) {
			//only updating the dp array if greater value is found
			if(arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind]) {
				dp[ind] = 1 + dp[prev];
				hash[ind] = prev; //storing the index of the element 
			}
		}
	}

	int maxi = INT_MIN;
	int lastIndex = -1;
	for(int i=0; i<n; i++) {
		if(dp[i] > maxi) {
			maxi = dp[i]; //finding the max element
			lastIndex = i; //getting its index
		}
	}

	vector<int> result;
	result.push_back(arr[lastIndex]); //storing the max element in the result
	//looping till the element points to itself in the hash table which means
	//there is no smaller element than this element in the LIS
	while(hash[lastIndex] != lastIndex) {
		lastIndex = hash[lastIndex]; //getting the index of previous element
		result.push_back(arr[lastIndex]); //storing the previous element in result
	}
	//since the result obtained is reversed order, arrange it in correct order
	reverse(result.begin(), result.end());

	return result;
}
