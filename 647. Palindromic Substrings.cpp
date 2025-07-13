class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;

        //we are using "expand around center" approach to count the palindromes
        for(int i=0; i<s.size(); i++) {
            //odd length string case, center is at one character
            int l=i, r=i;
            while(l>=0 && r<s.size() && s[l] == s[r]) {
                count++;
                l--; r++;
            }
            //even length string case, center is at two characters
            l=i, r=i+1;
            while(l>=0 && r<s.size() && s[l] == s[r]) {
                count++;
                l--; r++;
            }
        }
        return count;
    }
};