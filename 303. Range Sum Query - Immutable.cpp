class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n+1, 0); //since the sum till i gets stored in the i+1 index of prefix
        for(int i=0; i<n; i++) {
            prefix[i+1] = prefix[i] + nums[i]; //sum till i plus the current nums[i]
        }
    }

    // | index             | prefix[i] represents | used for       |
    // | ----------------- | -------------------- | -------------- |
    // | `prefix[left]`    | sum before left      | starting point |
    // | `prefix[right+1]` | sum up to right      | ending point   |
    // | difference        | range [left..right]  | ✅ desired sum  |

    
    int sumRange(int left, int right) {
        //right+1 because the sum for exact right element gets stored in the i+1 index
        //but we use left directly because the range includes left so we need to subtract 
        //the sum till the index just before left which is stored at prefix[left]
        return prefix[right+1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */