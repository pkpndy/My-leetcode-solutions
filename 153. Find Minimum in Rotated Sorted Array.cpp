class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<r) { // l<r kyuki agar l==r ho jaye toh loop ruk jaye
            // r+l/2 kyuki minus karoge toh current window se chote numbers aane ke changes none lgte hain
            int mid = (r+l)/2;
            if(nums[r]<nums[mid]) {
                l=mid+1; //mid+1 kyuki mid ko toh hm already check krke isme aaye
            } else {
                r=mid;
            }
        }
        return nums[r];
    }
};