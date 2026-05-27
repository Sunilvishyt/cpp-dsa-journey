/******************************************************************************
Question : Time Needed to Buy Tickets (LeetCode : 2073) 
Description : There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.
      You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].
      Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.
      Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.
time complexity : O(n^2)
space complexity : O(n)
*******************************************************************************/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int time = 0;

        //put the indexes in the q and rotate them and update the values in the array.
        for (int i = 0; i < tickets.size(); i++){
            q.push(i);
        }

        while (tickets[k] != 0){
            tickets[q.front()]--;
            time++;

            if (tickets[q.front()] == 0){
                q.pop();
            }
             
            else {
                q.push(q.front());
                q.pop();
            }
        }

        return time;
    }
};
