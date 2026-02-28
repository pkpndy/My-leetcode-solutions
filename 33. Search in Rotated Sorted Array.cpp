class Solution {
public:
    int bs(vector<int>& nums, int target, int l, int r) {
        while(l<=r) { //let the loop run till both reach at the same point
            int mid = l + (r-l) / 2; 
            if(nums[mid] == target) return mid; //ye wala target khojne ke liye hain
            if(nums[mid] > target) {
                r = mid-1; // we already checked for mid
            } else {
                l = mid+1; // we already checked for mid
            }
        }
        return -1; // if not found
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)  return -1;

        //find pivot (minimum element)
        int l=0, r=n-1;
        while(l<r) { // dono ek sath aaye toh loop ruk jaye
            int mid = l + (r-l) / 2; // aise large cases le liye overflow nhi hota
            if(nums[mid]>nums[r])   l=mid+1; //we are finding minimum
            else    r=mid;
        }
        int pivot = r; // last mein minimum pe rahega

        // low mein 0 aur high mein n-1 bhejna kyuki pivot khojne mein values hil gyi hn
        int lres = bs(nums, target, 0, pivot-1);
        if(lres != -1)  return lres;

        return bs(nums, target, pivot, n-1);
    }
};