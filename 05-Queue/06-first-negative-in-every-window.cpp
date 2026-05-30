/******************************************************************************
Question : First negative in every window of size k (gfg) 
Description : Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.
        Note: If a window does not contain a negative integer, then return 0 for that window.
time complexity : O(n)
space complexity : O(k)
*******************************************************************************/

class Solution {
	public:
	
	int display(queue<int>q) {
		if (!q.empty()) {
			return q.front();
		}
		return 0;
	}
	
	vector<int> firstNegInt(vector<int>& arr, int k) {
		// write code here
		queue<int>q;
		vector<int>ans;
		
		for (int i = 0; i < k - 1; i++) {
			if (arr[i] < 0)
				q.push(arr[i]);
		}
		
		for (int i = k - 1; i<arr.size(); i++) {
			if (arr[i] < 0)
				q.push(arr[i]);
			
			ans.push_back(display(q));
			int element_to_pop = arr[i - k + 1];
			if (!q.empty() and q.front() == element_to_pop)
				q.pop();
		}
		
		return ans;
	}
	
};
