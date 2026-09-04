/******************************************************************************
Question : Height of Heap (GFG) 
Description :Given a Binary Heap of size n in an array arr[]. Write a program to calculate the height of the Heap.
    Note: Return 1 if the n is 1.
time complexity : O(n)
space complexity : O(n)
*******************************************************************************/

class Solution {
	public:
	
	int find(int arr[], int n, int root) {
	    if (root >= n) return 0;
	    
	    //go to left child
	   int leftHeight = find(arr, n, 2*root+1);
	   
	   //go to right child
	   int rightHeight = find(arr, n, 2*root+2);
	   
	   return 1 + max(leftHeight, rightHeight);
	    
	}
	
	int heapHeight(int n, int arr[]) {
		if (n == 1) return 1;
		
		int height = find(arr, n, 0);
		return height - 1 ; //because we need to cound edges
	}
};


/***o(logn) solution**********************************************************************************/
// we use the formula here because n is already given.
class Solution {
	public:
	
	int heapHeight(int n, int arr[]) {
		if (n == 1) return 1;
		
		int height = 0;
		
		while (n > 1){
		    height += 1;
		    n = n / 2;
		}
		
		return height; //because we need to cound edges
	}
};

