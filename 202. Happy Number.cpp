class Solution {
public:
    int nextNumber(int n) {
        int total = 0;

        while(n>0) {
            int digit = n%10;
            total += digit*digit;
            n /= 10;
        }
        return total;
    }

    bool isHappy(int n) {
        int slow=n;
        int fast=nextNumber(n);

        //&& kyuki dono true ho, mtlb happy number nhi mila aur cycle nhi mila tb tk chalte raho
        while(fast != 1 && slow != fast) {
            slow=nextNumber(slow);
            fast=nextNumber(nextNumber(fast));
        }

        return fast==1;
    }
};