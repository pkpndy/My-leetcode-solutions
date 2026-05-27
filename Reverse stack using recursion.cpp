
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
    if(st.empty())  return;
    int tp = st.top();
    st.pop();

    reverseStack(st);

    // there are two ways for inserting the top popped element
    // at the bottom after the stack is reversed using recursion
    // one is by using auxiliary stack the taken O(n) space
    
    // stack<int> aux;
    // while(!st.empty()) {
    //     aux.push(st.top());
    //     st.pop();
    // }

    // st.push(tp);
    // while(!aux.empty()) {
    //     st.push(aux.top());
    //     aux.pop();
    // }

    //another way to insert the top element at the bottom by using recursion
    insertAtBottom(st, tp);
}
