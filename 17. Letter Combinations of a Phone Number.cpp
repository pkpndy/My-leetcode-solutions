class Solution {
private:
void giveLC(int i, string currStr, string digits, vector<string>& res, vector<string> digitToChar) 
    {
        if(digits.size() == currStr.size()) { //if for "23" one of the currStr will be "ae"
            res.push_back(currStr);
            return; 
        }
        //taking string from the vector mapping
        string chars = digitToChar[digits[i] - '0']; //char minus '0' gives its value from 0 int
        //for each char in the string we just extracted
        for(char c : chars) { // this will have "abc"
            //we call the function for next char in digits as we are using digits[i]
            giveLC(i+1, currStr + c, digits, res, digitToChar); // then loop will call it for "def"
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())  return res;
        //we create an actual vector mapping index to strings, since 0 and 1 have no chars on them
        vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", 
                                        "mno", "pqrs", "tuv","wxyz"};
        giveLC(0, "", digits, res, digitToChar);
        return res;
    }
};