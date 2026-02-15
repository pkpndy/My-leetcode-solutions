class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<pair<int, int>> st; //{temperature, index}

        //next greater right khojna hai
        for(int i=0; i<n; i++) {
            //jbtk abhi wale temperature se zyada temperature stack top mein milta hai
            while(!st.empty() && temperatures[i] > temperatures[st.top().second]) {
                int index = st.top().second;
                ans[index]=i-index;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        // last mein jo jo stack mein reh gye unko unse zyada temperature wale din nhi mile
        while(!st.empty()) {
            int index = st.top().second;
            ans[index]=0;
            st.pop();
        }
        return ans;
    }
};