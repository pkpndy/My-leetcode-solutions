class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false; //if the strings are not equal length then false
        unordered_map<char, int> mpp; //we will keep the track of frequency of each character

        for(int i=0; i<s.size(); i++) {
            mpp[s[i]]++; //increase the frequency of each character in the first string
        }

        for(int i=0; i<t.size(); i++) {
            if(mpp.find(t[i]) == mpp.end()) return false; //if any character of the second string is not present in the map
            mpp[t[i]]--; //decrease the frequency since we already found one match for that character
            if(mpp[t[i]]<0) return false; //for the cases where we got one same character extra in the second string like aacc ccac
        }
        
        return true;
    }
};
