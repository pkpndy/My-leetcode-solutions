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
	int maxi = INT_MIN; //storing the max value and its index helps in printing the LIS
	int lastIndex = -1;

	for(int ind=0; ind<n; ind++) {
		//this will be usefult to end the storing of elements in the result array
		hash[ind] = ind;

		for(int prev=0; prev<ind; prev++) {
			//if element at previous(arr[prev]) is smaller than current index element
			//and if adding the LIS till previous element(1 + dp[prev]) > LIS till current element(dp[ind]) till now
			if(arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind]) {
				dp[ind] = 1 + dp[prev];
				hash[ind] = prev; //storing the index of the element 
			}
		}

		if(dp[ind] > maxi) {
			maxi = dp[ind]; //finding the max element
			lastIndex = ind; //storing its index
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
