/*
You are given an expression 'exp' in the form of a string where operands will be : (TRUE or FALSE), and operators will be : (AND, OR or XOR).

Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.

As the answer can be very large, return the output modulo 1000000007.
Note :

‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.
Example :

Input: 'exp’ = "T|T & F".

Output: 1

Explanation:
There are total 2  ways to parenthesize this expression:
    (i) (T | T) & (F) = F
    (ii) (T) | (T & F) = T
Out of 2 ways, one will result in True, so we will return 1.
*/

#define ll long long
int MOD = 1000000007;
ll gt(int i, int j, bool isTrue, string& exp, vector<vector<vector<ll>>>& dp) {
    if(i>j) return 0; //if i crosses j no further partition is possible
    if(i==j) { //if i and j are at the same operand, means it's either 'T' or 'F'
        if(isTrue)  return exp[i] == 'T'; //if we were looking for true(for making the end result true) give 1
        else return exp[i] == 'F'; //if we were looking for true(for making the end result true) give 1
    }
    if(dp[i][j][isTrue] != -1)  return dp[i][j][isTrue];
    ll ways = 0;

    // "T | T & F ^ T"
    //  i           j

    //the partitions happen at the operators,
    //so the first operator is at i+1 and last is at j-1 and each one of them is at a distance of +2
    for(int k=i+1; k<=j-1; k+=2) {
        ll lT = gt(i, k-1, 1, exp, dp); //get the number of ways we can make left partition true
        ll lF = gt(i, k-1, 0, exp, dp); //get the number of ways we can make left partition false
        ll rT = gt(k+1, j, 1, exp, dp); //get the number of ways we can make right partition true
        ll rF = gt(k+1, j, 0, exp, dp); //get the number of ways we can make right partition false

        //number of ways till now + when the conditions in which the operator gives true or false
        if(exp[k] == '&') { //if the operator is &
            if(isTrue)  ways = (ways + (lT*rT))%MOD; //if we want a true to make the whole evaluation true
            //if we want a false to make the whole evaluation true
            else    ways = (ways + ((lF*rT)%MOD + (rF*lT)%MOD + (lF*rF)%MOD))%MOD;
        } else if (exp[k] == '|') { //if the operator is false
            if(isTrue)  ways = (ways + ((lT*rT)%MOD + (lF*rT)%MOD + (rF*lT)%MOD))%MOD;
            else    ways = (ways + (lF*rF))%MOD;
        } else {
            if(isTrue)  ways = (ways + ((lF*rT)%MOD + (rF*lT)%MOD))%MOD;
            else    ways = (ways + ((lT*rT)%MOD + (lF*rF)%MOD))%MOD;
        }
    }
    return dp[i][j][isTrue] = ways%MOD;
}
int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, -1)));
    return gt(0, n-1, 1, exp, dp); //gt(start, end, we want number of trues exp, dp)
}