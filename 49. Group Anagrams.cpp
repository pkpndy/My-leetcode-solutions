class Solution {
public:
    string generate(string& word) {
        int arr[26] = {0}; //the hashmap to keep the count of frequency of each character

        for(char &ch: word) { //for each character in this word
            arr[ch-'a']++; //increase the frequency of that index that represents the character
        }

        string new_word = "";

        for(int i=0; i<26; i++) {
            if(arr[i] > 0) { //for any index that has frequency greater then 0
                int freq = arr[i]; //get the frequency of that character
                new_word += string(freq, i+'a'); //add this character that many times to the key that will be added in the map
            }
        }
        return new_word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp; //we will create a group for each unique character that will act as a key
        vector<vector<string>> result;
        if(strs.empty())    return result;

        for(int i=0; i<strs.size(); i++) {
            string word = strs[i]; //pick each string one by one

            string new_word = generate(word); //this will create the key for the current word like for "dog" it will be "dgo"

            mpp[new_word].push_back(word); //then push this current word to the group it belongs it, this will also handle new group keys
        }

        for(auto& it: mpp) { //iterate the map and pick each vector for unique set that will become the anagram
            result.push_back(it.second); //since the auto will make it a pair
        }
        return result;
    }
};
