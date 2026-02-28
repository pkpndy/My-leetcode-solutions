class Solution {
public:
    bool bsh(vector<vector<int>>& matrix, int target, int row, int l, int r) {
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(matrix[row][mid]==target)   return true;
            if(matrix[row][mid]<target)    l=mid+1;
            else    r=mid-1;
        }
        return false;
    }

    bool bsv(vector<vector<int>>& matrix, int target, int col, int t, int b) {
        while(t<=b) {
            int mid = t + (b-t)/2;
            if(matrix[mid][col]==target)    return true;
            if(matrix[mid][col]<target) t=mid+1;
            else        b=mid-1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int shortestDim = min(n, m);

        for(int l=0; l<shortestDim; l++) {
            if(bsh(matrix, target, l, l, m-1))  return true;
            if(bsv(matrix, target, l, l, n-1))  return true;
        }
        return false;

        // This is another way where we start at the top right
        // int row=0;
        // int col=m-1;

        // while(row<n && col>=0) {
        //     if(matrix[row][col]==target)    return true;
        //     if(matrix[row][col] > target)   col--;
        //     else    row++;  
        // }
        // return false;
    }
};