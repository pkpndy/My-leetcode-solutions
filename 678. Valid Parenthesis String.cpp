class Solution {
public:
    bool isValid(string& s, int position, int count, vector<vector<int>>& dp) {
        //check the count<0 first because if count is already below 0 everything else doesn't matter
        if(count<0) return false;

        if(position == s.size())  return count==0;

        if(dp[position][count] != -1)   return dp[position][count];

        bool res = false; //we take res to store the result returned by each count
        if(s[position]=='(') {
            res = isValid(s, position+1, count+1, dp);
        } else if(s[position]==')') {
            res = isValid(s, position+1, count-1, dp);
        } else { //if we found '*' then there can be 3 things, '', '(', ')'
            res = isValid(s, position+1, count, dp) || 
                isValid(s, position+1, count+1, dp) || 
                isValid(s, position+1, count-1, dp);
        }
        return dp[position][count] = res;
    }

    bool checkValidString(string s) {
        int n = s.size();
        //we have two changing states, index and the count
        vector<vector<int>> dp(n, vector<int> (n, -1));
        if(isValid(s, 0, 0, dp)) {
            return true;
        }
        return false;
    }

    bool checkValidString(string s) {
        int open=0, close=0; //we keep track of opening and closing bracket counts
        // forward pass: make sure we never have more ')' than '(' + '*'
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(') open++;
            else if(s[i]==')')  open--;
            else    open++;
            if(open<0)  return false; //we found more closing brackets
        }
        // backward pass: make sure we never have more '(' than ')' + '*'
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i]==')') close++;
            else if(s[i]=='(')  close--;
            else    close++;
            if(close<0)  return false; //we found more opening brackets
        }
        return true;
    }

    bool checkValidString(string s) {
        int n = s.size();
        int mini=0, maxi=0; //we use range based things
        for(int i=0; i<n; i++) {
            if(s[i] == '(') { //range will increase if we found '('
                maxi++;
                mini++;
            } else if(s[i] == ')') { //range will decrease if we found ')'
                mini--;
                maxi--;
            } else { // if * is found then it can become ( to decrease mini and ) to increase maxi
                mini--;
                maxi++;
            }
            if(mini<0)  mini=0; //we don't let mini go below 0
            if(maxi<0)  return false; //if the first char is ')' then no point in going further
        }
        return mini==0; //if mini is zero that means the string is valid paranthesis
    }
};