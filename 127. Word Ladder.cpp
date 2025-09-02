class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q; //we take queue for bfs traversal
        q.push({beginWord, 1}); //we start by pushing the beginWord and its level as 1
        unordered_set<string> st(wordList.begin(), wordList.end()); //we use set bcoz searching is faster
        st.erase(beginWord); //we remove that word after pushing it into the queue

        while(!q.empty()) {
            string word = q.front().first; //take out the front word
            int level = q.front().second; //take its level
            q.pop(); 
            if(word==endWord)   return level; //word matches the endWord then return the level
            for(int i=0; i<word.size(); i++) { //we traverse our current word
                char original = word[i]; //store the original letter
                for(char ch='a'; ch<='z'; ch++) { //we try all possible characters at that index
                    word[i]=ch; //change the letter
                    if(st.find(word) != st.end()) { //if the change in the letter found a match in set
                        q.push({word, level+1}); //push that into q and increase the level
                        st.erase(word); //erase the word from the set
                    }
                }
                word[i]=original; //replace the changed letter back to original
            }
        }
        return 0;
    }
};