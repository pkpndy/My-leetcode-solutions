class Solution {
public:
    //if got chance look for Manacher's algorithm

    /*
    //this is "expand around centers approach" takes TC:O(n^2)
    string longestPalindrome(string s) {
        string res = "";
        int resLen = 0;

        //in this approach at each index we spread arounf center
        //to check if the substring formed is a palindrome or not
        for(int i=0; i<s.size(); i++) {
            //odd length string will have single center
            //check for i=0->"b", i=1->"a", "bab", i=2-> "b", "aba", "babad" 
            int l = i, r = i;
            while(l>=0 && r<s.size() && s[l] == s[r]) {
                if(r-l+1 > resLen) {
                    resLen = r-l+1;
                    res = s.substr(l, r-l+1); //substr(start, length of subtring)
                }
                l--; r++;
            }
            //even length string will have two centers
            //check for i=0->"cb", i=1->"bb", "cbbd"
            l=i; r=i+1;
            while(l>=0 && r<s.size() && s[l] == s[r]) {
                if(r-l+1 > resLen) {
                    resLen = r-l+1;
                    res = s.substr(l, r-l+1); //substr(start, length of subtring)
                }
                l--; r++;
            }
        }
        return res;
    }
    */

    /*
    //this is brute force approach having TC:O(n^3) solution 
    void giveSubstrings(int idx, string& longest, string& s) {
        if(idx == s.size()) {
            return;
        }
        
        for(int i=idx; i<s.size(); i++) {
            if(checkPal(s, idx, i)) {
                string currStr = s.substr(idx, i-idx+1);
                longest = longest.length() > currStr.length() ? longest : currStr;
            }
        }
        giveSubstrings(idx+1, longest, s);
    }

    bool checkPal(string s, int start, int end) {
        while(start<=end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    string longestPalindrome(string s) {
        if(s.size() == 1)   return s;
        string longest = "";
        giveSubstrings(0, longest, s);
        return longest;
    }
    */
};