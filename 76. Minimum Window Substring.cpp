class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if(t.size() > n) { //if the string we are trying to find is greater
            return "";
        }

        //we will store the frequency of all the characters be it in s or t
        unordered_map<char, int> freq; //{character, frequency}
        for(char &c: t)  freq[c]++; //store the frequency of characters present in t

        //store the number of characters present in t,
        //this will help in checking if we found the characters in our current window
        int reqCount = t.size();
        int minWindowSize = INT_MAX; //to only store the min size window
        int start_i = 0; //for cutting the substring from s
        int i=0, j=0; //the two pointers
        
        while(j<n) { //till j doesn't cross the n
            char ch = s[j]; //for every j we check

            //if the character we found is one of the character we were looking for
            if(freq[ch] > 0)  reqCount--; //decrease the required char count

            //we decrease the frequency irrespective of if it was present in t or not
            freq[ch]--;
            
            //start shrinking the window, to get the minWindow and required count is still 0
            while(reqCount == 0) { //if we found all the characters we needed
                int currWindowSize = j-i+1; //calculate the current window size

                if(currWindowSize < minWindowSize) { //check if its minimum
                    minWindowSize = currWindowSize;
                    start_i = i; //store the starting of this min window
                }

                //we are excluding the character from the window then 
                //increase its frequency back
                freq[s[i]]++;

                //if this character's freq increase above 0 that means this 
                //was one of the required characters
                if(freq[s[i]] > 0) reqCount++;

                i++; //increase i to shrink window
            }
            j++; //increase j to expand window
        }

        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};