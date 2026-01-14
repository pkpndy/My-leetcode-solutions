class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //kyuki question mein agle warm din ko pucha hai
        //hm temp array mein peeche se aate time agle warm din ko store rkhenge 
        //fir colder din store krte jayenge

        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n, 0);
        for(int i=n-1; i>=0; i--) { //peeche se traverse kr rhe hain temperatures array ko
        //jb tk stack khali nhi hai aur stack ke top pe aaj wale din se thande din bhre hue hain
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop(); //tb tk stack khali karo
            }
            if(!st.empty()) { //agar stack khali nhi hua mtlb zarur aage koi warmer din hoga
               res[i] = st.top() - i; //difference between both the days
            }
    
            st.push(i); //ye sb ke baad din ko push kr do wo array mein aage se aane pe sbse garam din hoga
        }
        return res;
    }
};