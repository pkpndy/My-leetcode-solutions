class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j) {
            while(i<j && !isalnum(s[i]))    i++; //skip the character if its not alphanumeric
            while(i<j && !isalnum(s[j]))    j--; //skip the character if its not alphanumeric
            //convert in lowercase for checking as its asked to do in the question
            if(tolower(s[i]) != tolower(s[j]))  return false;
            i++;
            j--;
        }
        return true;
    }
};