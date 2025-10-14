class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n <= 1) return n;
        unordered_map<char, int> lastIndex; //{character, last seen index}
        int i=0;
        int maxlen=0;
        for(int j=0; j<n; j++) {
            char c = s[j];

            //if the character is present in the map and also is currently in our window
            if(lastIndex.count(c) && lastIndex[c] >= i) {
                i = lastIndex[c]+1;
            }

            lastIndex[c]=j; //update the new index
            maxlen = max(maxlen, j-i+1); //calculate the max length found
        }
        return maxlen;
    }
};