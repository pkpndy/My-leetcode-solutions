#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

//this question requires topological sort, as there are characters dependent
//on other characters in a dictionary, just like lexical order
string getAlienLanguage(vector<string> &dictionary, int k)
{
    vector<vector<int>> adjList(k);
    int n = dictionary.size();
    vector<int> indegree(k, 0);

    for(int i=0; i<n-1; i++) { //we compare two strings each time, s[i] and s[i+1]
        string s1 = dictionary[i];
        string s2 = dictionary[i+1];
        int len = min(s1.size(), s2.size()); //we only compare till the smaller string
        for(int j=0; j<len; j++) {
            if(s1[j] != s2[j]) { //whenever we find a mismatching character
                //in "aaa" and "aab", a comes before b, this is a dependency 
                //this means its like an edge from a to b, a->b
                adjList[s1[j] - 'a'].push_back(s2[j] - 'a');
                //storing the num value of the character from 0 (minus 'a' gives that)

                indegree[s2[j] - 'a']++; //increasing the indegree of that number

                //we break out of the loop after only one character because just like dictionary 
                //only the first change in character determines the word will come before or after
                break; 
            }
        }
    }

    vector<int> result;
    queue<int> q;
    for(int i=0; i<k; i++)  if(indegree[i] == 0)    q.push(i);

    while(!q.empty()) {
        int node = q.front(); q.pop();
        result.push_back(node);

        for(int adj : adjList[node]) {
            indegree[adj]--;
            if(indegree[adj]==0)    q.push(adj);
        }
    }

    if (result.size() != k) { //if we found a cycle and stopped the toposort
        return "";
    }

    string ans = "";
    for(auto it : result) {
        ans += char(it + 'a'); //changing the number back to character
    }

    return ans;
}