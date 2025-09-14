class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (!dict.count(endWord)) return result;

        unordered_map<string, vector<string>> parents; // adjacency list (reverse graph)
        unordered_set<string> current, next;
        current.insert(beginWord);

        bool found = false;

        while (!current.empty() && !found) {
            for (auto& w : current) dict.erase(w); // remove used words to prevent revisits

            for (auto& word : current) {
                string s = word;
                for (int i = 0; i < s.size(); i++) {
                    char original = s[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        s[i] = c;
                        if (!dict.count(s)) continue;
                        next.insert(s);
                        parents[s].push_back(word); // store path
                        if (s == endWord) found = true;
                    }
                    s[i] = original;
                }
            }
            current.swap(next);
            next.clear();
        }

        if (!found) return result;

        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parents, path, result);
        return result;
    }

private:
    void backtrack(string word, string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path,
                   vector<vector<string>>& result) {
        if (word == beginWord) {
            vector<string> temp(path.rbegin(), path.rend());
            result.push_back(temp);
            return;
        }
        for (auto& p : parents[word]) {
            path.push_back(p);
            backtrack(p, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};
