/***************************************************************************************/
// print queue elements (items should be there after printing).
    queue<int>q;
    
    q.push(2);
    q.push(6);
    q.push(9);
    q.push(2);
    
    int n = q.size();
    
    for (int i = 0; i < n; i++){
        cout << q.front() <<endl;
        q.push(q.front());
        q.pop();
    }

/***************************************************************************************/
// reverse elements of queue

    queue<int>q;
    
    q.push(2);
    q.push(6);
    q.push(9);
    q.push(2);
    
    stack<int>st;
    
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }


/***************************************************************************************/
