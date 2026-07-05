class Solution {
public:
    string generate(string& word) {
        int arr[26] = {0};

        for(char &ch: word) {
            arr[ch-'a']++;
        }

        string new_word = "";

        for(int i=0; i<26; i++) {
            if(arr[i] > 0) {
                int freq = arr[i];
                new_word += string(freq, i+'a');
            }
        }
        return new_word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> result;
        if(strs.empty())    return result;

        for(int i=0; i<strs.size(); i++) {
            string word = strs[i];

            string new_word = generate(word);

            mpp[new_word].push_back(word);
        }

        for(auto& it: mpp) {
            result.push_back(it.second);
        }
        return result;
    }
};
