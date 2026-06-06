#include <bits/stdc++.h> 

void solve(int x, int y, vector<string>& ans, string& res, vector<vector<int>>& arr) {
    // base cases will be out of bounds and not 1 then return
    if(x<0 || y<0 || x>=arr.size() || y>=arr.size() || arr[x][y]==0)    return;

    // if reached the last block and it is 1 then it is one of the paths
    if(x==arr.size()-1 && y==arr.size()-1 && arr[x][y]==1) {
        ans.push_back(res);
        return;
    }

    arr[x][y]=0; //set the current block as visited

    //then explore all the directions
    res.push_back('R');
    solve(x, y+1, ans, res, arr);
    res.pop_back();

    res.push_back('D');
    solve(x+1, y, ans, res, arr);
    res.pop_back();

    res.push_back('L');
    solve(x, y-1, ans, res, arr);
    res.pop_back();

    res.push_back('U');
    solve(x-1, y, ans, res, arr);
    res.pop_back();

    arr[x][y]=1; //after exploring all directions backtrack and mark current block as unvisited
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    if(arr[0][0]==0 || arr[n-1][n-1]==0)    return {};
    vector<string> ans;
    string res;
    solve(0, 0, ans, res, arr);

    sort(ans.begin(), ans.end()); //because the question asked for lexicographical order

    return ans;
}
