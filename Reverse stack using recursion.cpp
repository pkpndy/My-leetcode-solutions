#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int>& st, int element) {
    if(st.empty()) {
        st.push(element);
        return;
    }
    int auxtop = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(auxtop);
}

void reverseStack(stack<int> &st) {
    if(st.empty())   return;
    int tp = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st, tp);
}
