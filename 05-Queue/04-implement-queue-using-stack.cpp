/******************************************************************************
Question : Implement Queue using Stacks (LeetCode : 232) 
Description : Implement a first in first out (FIFO) queue using only two stacks. 
    The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
time complexity : 
space complexity : 
*******************************************************************************/

class MyQueue {
public:
    stack<int>st;
    stack<int>st2;

    MyQueue() {
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }

        int r = st2.top();

        st2.pop();

        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }

        return r;
    }
    
    int peek() {
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }

        int r = st2.top();

        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }

        return r;
    }
    
    bool empty() {
        return st.empty();
    }
};

