string minWindow(string s, string t) {
        //if there is no string t to check in s
        if(t.size() == 0)   return "";

        // hashmap for chars freq in t and our current window
        unordered_map<char, int> window, countT;
        for(char c: t) { // storing freq of chars in t
            countT[c]++;
        }

        // have is the total freq of chars matching in current window and countT
        // need is the total equal freq of chars we need 
        int have=0, need=countT.size();
        // to store the start and end of current result string
        pair<int, int> res = {-1, -1};

        // to store the length of the resulting string as in the
        // end the r will cross the string size due to iteration
        int resLen = INT_MAX;
        int l=0;

        for(int r=0; r < s.size(); r++) {
            char c = s[r]; 
            window[c]++; // increase the freq of current char

            if(countT.count(c) && window[c] == countT[c]) {
                // if curr char exists in t and the freq of char
                // is equal in our current window and t
                have++;
            }

            while(have == need) {
            // till have and need are equal store the minimum length
            // of string required to keep the resulting solution
                if(r - l + 1 < resLen) {
                    resLen = r-l+1;
                    res = {l, r};
                }

                // decrease the freq of the char at l as 
                // it is window is sliding and moving forward
                window[s[l]]--;

                //if char at l exists in t and when you decrement window[s[l]]--              
                //(because you're sliding l++), the count of that character 
                //might drop below what's needed.
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        //if the no changes was done in resLen means no result found
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }