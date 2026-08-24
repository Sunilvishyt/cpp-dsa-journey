// deletion in heap /////////////////////////////////////////////////////////////////////////////////////////////////////////
//time complexity logn (n items so nlogn)


#include <iostream>
#include <print>
#include <vector>
using namespace std;

class MaxHeap {
	vector<int>arr;

public:

	void insert(int val) {
		arr.push_back(val);
		int index = arr.size() - 1;

		while (index > 0 && arr[(index - 1)/2] < arr[index]) {
			swap(arr[(index - 1) / 2], arr[index]);

			index = (index - 1) / 2;
		}

		print("{} is pushed in the array.", val);
		cout << "\t";
		print("Array : {}", arr);
		cout << endl;
	}

	void Delete() {
		int parentIdx = 0;
		arr[0] = arr[arr.size() -1];
		arr.pop_back();

        cout << arr[parentIdx]<<  " is deleted " << "\t\t\t";
        
		while (true) {

			//find biggest children to swap parent with.
			int biggestChildIdx;
			int leftChildIdx = 2*parentIdx+1;
            int rightChildIdx = 2*parentIdx+2;

			//both childs doesnot exists
			if (leftChildIdx >= arr.size()) break;

			//only left child exits
			else if (leftChildIdx < arr.size() && rightChildIdx >= arr.size()) {
				biggestChildIdx = leftChildIdx;
			}

			else {
				int largest = max(arr[leftChildIdx], arr[rightChildIdx]);

				if (largest == arr[leftChildIdx]) {
					biggestChildIdx = leftChildIdx;
				}
				else biggestChildIdx = rightChildIdx;
			}

			//swap parent with children
			if (arr[parentIdx] < arr[biggestChildIdx])
				swap(arr[parentIdx], arr[biggestChildIdx]);

			parentIdx = biggestChildIdx;
		}
		
		print("Array after deletion : {}",arr);
		cout << endl;
	}
};

int main()
{
	MaxHeap h;
	h.insert(5);
	h.insert(10);
	h.insert(2);
	h.insert(100);
	h.insert(77);
	h.Delete();
	h.Delete();
	return 0;
}
