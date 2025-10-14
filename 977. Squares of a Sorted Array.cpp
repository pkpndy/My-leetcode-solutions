class Solution {
public:
    //here we are using two pointers approach we are comparing the numbers from both the ends
    //and storing them starting from the end of the result vector for whichever is greater
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=n-1;
        vector<int> result(n);
        int x=n-1;
        while(i<=j) { //<= because if there are odd number of elements in the array
            int leftsq = nums[i]*nums[i];
            int rightsq = nums[j]*nums[j];

            if(leftsq <= rightsq) {
                result[x]=rightsq;
                j--;
            } else {
                result[x]=leftsq;
                i++;
            }
            x--;
        }
        return result;
    }
};