/******************************************************************************
Question : Kth Smallest (GFG) 
Description : Given an integer array arr[] and an integer k, find and return the kth smallest element in the given array.
    Note: Return 1 if the n is 1.
*******************************************************************************/

/**O(nlogn) TC and O(1) SC solution****************************************************************************************************/
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};


/**O(klogn) TC and O(1) SC solution****************************************************************************************************/
//using step down approch (Floyd's Heap Construction)
class Solution {
	public:
	
	void minHeapCreate(vector<int>&arr, int i) {
		while (true) {
			int leftChildIdx = i * 2 + 1;
			int rightchildIdx = i * 2 + 2;
			int smallestChildIdx;
			
			// no child exists
			if (leftChildIdx > arr.size() - 1 && rightchildIdx > arr.size() - 1) {
				return;
			}
			
			// if left child only exists
			if (leftChildIdx < arr.size() && rightchildIdx > arr.size() - 1) {
				smallestChildIdx = leftChildIdx;
			}
			
			// if both child exists
			else {
				int currentMin = min(arr[leftChildIdx], arr[rightchildIdx]);
				if (currentMin == arr[leftChildIdx])
					smallestChildIdx = leftChildIdx;
				else
					smallestChildIdx = rightchildIdx;
			}
			
			if (arr[i] > arr[smallestChildIdx])
				swap(arr[i], arr[smallestChildIdx]);
			
			i = smallestChildIdx;
		}
		
	}
	
	void Heapify(vector<int>&arr) {
		int i = 0;
		
		while (true) {
			
			int leftChildIdx = i * 2 + 1;
			int rightchildIdx = i * 2 + 2;
			int smallestChildIdx;
			
			// no child exists
			if (leftChildIdx > arr.size() - 1 && rightchildIdx > arr.size() - 1) {
				return;
			}
			
			// if left child only exists
			if (leftChildIdx < arr.size() && rightchildIdx > arr.size() - 1) {
				smallestChildIdx = leftChildIdx;
			}
			
			// if both child exists
			else {
				int currentMin = min(arr[leftChildIdx], arr[rightchildIdx]);
				if (currentMin == arr[leftChildIdx])
					smallestChildIdx = leftChildIdx;
				else
					smallestChildIdx = rightchildIdx;
			}
			
			if (arr[i] > arr[smallestChildIdx])
				swap(arr[i], arr[smallestChildIdx]);
			
			i = smallestChildIdx;
			
		}
	}
	
	void minHeapDelete(vector<int>&arr) {
		swap(arr[0], arr[arr.size() - 1]);
		arr.pop_back();
		Heapify(arr);
	}
	
	int kthSmallest(vector<int> &arr, int k) {
		for (int i = (arr.size()/2) - 1 ; i >= 0; i--) {
			minHeapCreate(arr, i);
		}
		for (int i = 0; i < k-1 ; i++) {
			minHeapDelete(arr);
		}
		
		return arr[0];
	}
};

