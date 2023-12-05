// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

// Function for calculating
// minimum opeartions
int minimum_operations(vector<int>& arr, int n)
{

	// Declare map for storing the index
	// of each element.
	map<int, vector<int> > mpp;
	for (int i = 0; i < arr.size(); i++) {
		mpp[arr[i]].push_back(i);
	}

	// Declare queue which store the count
	// of previously non zero element.
	queue<int> q;
	set<int> st;

	// Count the total opeartions
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		if (st.find(arr[i]) == st.end() && arr[i] != 0) {
			q.push(arr[i]);
			st.insert(arr[i]);
		}

		// If found the violating condition
		if (arr[i] > arr[i + 1]) {

			// Increase the count by the
			// previously non zero elements
			count += q.size();
			while (!q.empty()) {
				int top = q.front();
				q.pop();

				if (mpp.find(top) != mpp.end()) {

					// Set all occurences of
					// previously assigned zero
					// elements to zero
					vector<int> idx = mpp[top];
					for (int i = 0; i < idx.size(); i++) {
						arr[idx[i]] = 0;
					}
				}
			}
		}
	}

	// Returning the count
	return count;
}

// Driver code
int main()
{
	vector<int> arr = { 4, 1, 5, 3, 2 };
	int n = arr.size();

	// Function call
	cout << minimum_operations(arr, n);
	return 0;
}
