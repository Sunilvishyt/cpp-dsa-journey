/******************************************************************************
Question : Reverse first k elements of queue (gfg) 
Description : Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.
time complexity : O(n)
space complexity : O(n)
*******************************************************************************/

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
      //if k is larger that the size of q size then we dont have to reverse anything.
        if (k > q.size()) return q;
        
        stack<int>st;
        int n = q.size();
        
        for(int i = 0; i < k; i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        int operations = n - k;
        
        for (int i = 0; i < operations; i++){
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};
