class Solution {
public:
    //uses LIS pattern
    bool isValid(string& str1, string& str2) {
        //the longer word should be only one character longer
        if(str2.size() != str1.size() + 1)  return false;
        int i=0, j=0;
        while(j < str2.size()) { //since j will cross the word if it doesn't find any match
            //till shorter word is not traversed and characters in both match
            if(i < str1.size() && str1[i] == str2[j]) {
                i++; j++; //move the pointers forward
            } else {
                j++; //move j if chars dont match
            }
        }
        if(i == str1.size() && j == str2.size())    return true; //return true if both completed traversal
        else return false; //else return false
    }

    static bool comparator(string& str1, string& str2) {
        return (str1.size() < str2.size()); //sort according to the string size
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int maxi = 0;
        vector<int> dp(n, 1); //dp array to store the longest string chain(LIS) till that index

        sort(words.begin(), words.end(), comparator); //sort the words array according to the size of strings

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(isValid(words[j], words[i])) { //check if the words are valid to make a string chain
                    if(1 + dp[j] > dp[i]) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if(dp[i] > maxi)    maxi = dp[i];
        }
        return maxi;
    }
};