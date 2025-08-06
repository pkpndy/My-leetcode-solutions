/*
A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then strictly decreasing.

A strictly ascending order sequence is also considered bitonic, with the decreasing part as empty, and same for a strictly descending order sequence.

For example, the sequences [1, 3, 5, 3, 2], [1, 2, 3, 4] are bitonic, whereas the sequences [5, 4, 1, 4, 5] and [1, 2, 2, 3] are not.

You are given an array 'arr' consisting of 'n' positive integers.

Find the length of the longest bitonic subsequence of 'arr'.

Example :
Input: 'arr' = [1, 2, 1, 2, 1]

Output: 3

Explanation: The longest bitonic subsequence for this array will be [1, 2, 1]. Please note that [1, 2, 2, 1] is not a valid bitonic subsequence, 
because the consecutive 2's are neither strictly increasing, nor strictly decreasing.
*/

int longestBitonicSubsequence(vector<int>& arr, int n)
{
    //we use two dp vectors and fill them once by iterating the arr from front then back
	vector<int> dpf(n, 1), dpb(n, 1);

	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			if(arr[j] < arr[i] && 1 + dpf[j] > dpf[i]) {
				dpf[i] = 1 + dpf[j];
			}
		}
	}
	
	for(int i=n-1; i>=0; i--) {
		for(int j=n-1; j>i; j--) {
			if(arr[j] < arr[i] && 1 + dpb[j] > dpb[i]) {
				dpb[i] = 1 + dpb[j];
			}
		}
	}

	int maxi=0;
	vector<int> bitonic(n, 1);
	for(int i=0; i<n; i++) {
        //we sum the elements of the dp arrays and -1 because the highest number gets included twice
		bitonic[i] = (dpf[i] + dpb[i]) - 1;
		maxi = max(bitonic[i], maxi);
	}

	return maxi;
}
