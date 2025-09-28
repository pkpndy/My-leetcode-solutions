class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size()==0 || s.size()==0)  return 0;
        //sort both the arrays, since the order of the elements don't matter for the result
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size();
        int m = s.size();
        int count=0;

        int i=0, j=0;
        while(i<n && j<m) {
            if(g[i]<=s[j]) { //if greed of the kid is less than or equal to the size of the cookie
                count++; //no. of content kid increases
                i++; //kid stomach full
                j++; //cookie got eaten
            } else {
                j++; //cookie ignored as its small for any of the kids left
            }
        }

        return count;
    }
};