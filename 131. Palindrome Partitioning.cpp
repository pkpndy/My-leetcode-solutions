/*
"aab" - we want to partition this into palindromes

Call: idx=0 (start building partition from position 0)
├── i=0: Try segment [0,0] = "a" ✓ palindrome
│   │    Current partition: ["a"]
│   └── Recurse: idx=1 (next segment starts at position 1)
│        ├── i=1: Try segment [1,1] = "a" ✓ palindrome  
│        │    Current partition: ["a","a"]
│        └── Recurse: idx=2 
│             ├── i=2: Try segment [2,2] = "b" ✓ palindrome
│             │    Final partition: ["a","a","b"] ✓
│             └── Recurse: idx=3 (end of string)
│
├── i=1: Try segment [0,1] = "aa" ✓ palindrome
│   │    Current partition: ["aa"]  
│   └── Recurse: idx=2 (next segment starts at position 2)
│        └── i=2: Try segment [2,2] = "b" ✓ palindrome
│             Final partition: ["aa","b"] ✓
│
└── i=2: Try segment [0,2] = "aab" ✗ not palindrome
*/

class Solution {
public:
    void givePartition(int idx, string s, vector<string>& ds, vector<vector<string>>& res)
    {
        //if the recursive call reaches end that means we were successful in partitioning
        if(idx == s.size()) {
            res.push_back(ds);
            return;
        }

        //in each call we check for possible partition from that point till last
        for(int i = idx; i<s.size(); i++) {
            if(isPalindrome(s, idx, i)){ //check for the substring from current index till i
                //in substr the end is exclusive hence we do +1 to also include the last character
                ds.push_back(s.substr(idx, i-idx+1));
                //the current partition is from idx to i, so next segment will start from i+1
                givePartition(i+1, s, ds, res);
                ds.pop_back(); //backtrack
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            //here comparison happends first then increment/decrement happens for start and end
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res; //for storing all the partitioned strings
        vector<string> ds; //for storing all the strings after a partition path
        givePartition(0, s, ds, res);
        return res;
    }
};

