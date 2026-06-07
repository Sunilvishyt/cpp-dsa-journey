/******************************************************************************
Question : Sliding Window Maximum (LeetCode : 239) 
Description : You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
      Return the max sliding window.
time complexity : O(n)
space complexity : O(k)
*******************************************************************************/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int n = nums.size();

        for (int i = 0; i < k - 1; i++){
            if (dq.empty()){
                dq.push_back(i);
            }
            else {
                while (!dq.empty() && nums[i] > nums[dq.back()]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }

        for (int i = k-1; i < n; i++){
            
            while (!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);


            if (dq.front() <= i - k ){
                dq.pop_front();
            }
            
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
