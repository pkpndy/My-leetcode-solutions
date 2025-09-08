/*
This question is on geeks for geeks

Minimum Multiplications to reach End
Given start, end and an array arr of n numbers. 
At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Example 1:

Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30
*/


class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end)  return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //{steps, result}
        //since the multiplications can give any number between 0 to 99999, but the mod is 100000
        vector<int> minMultiplications(100000, INT_MAX); //this will store the min multiplication steps to reach any number
        minMultiplications[start] = 0; //the min num of multiplications to reach start will be 0
        pq.push({0, start}); //{0 steps to reach start, starting number}
        
        while(!pq.empty()) {
            auto [steps, num] = pq.top();   pq.pop();
            if(num==end)    return steps;
            for(int it : arr) {
                int newNum = (it*num)%100000; // we took one more step(multiplication) here
                if(minMultiplications[newNum] > steps+1) { //newNum was reached by doing one more multiplication
                    minMultiplications[newNum]=steps+1; // store the number of multiplications taken to reach this newNum
                    pq.push({steps+1, newNum}); //push it into the queue
                }
            }
        }
        return -1;
    }
};
