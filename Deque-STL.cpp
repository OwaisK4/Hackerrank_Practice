#include <iostream>
#include <deque>
#include <algorithm>
#include <climits>
using namespace std;

void printKMax(int arr[], int n, int k){
	deque<int> subarray(arr, arr + k);
	int max;
	while (k <= n){
		// max = INT_MIN;
		// max = *max_element(subarray.begin(), subarray.end());
		// cout << max << " ";
		cout << *max_element(subarray.begin(), subarray.end()) << " ";
		// for (auto it = subarray.begin(); it != subarray.end(); it++){
		// 	if (max < *it)
		// 		max = *it;
		// }
		// cout << max << " ";
		subarray.push_back(arr[k]);
		subarray.pop_front();
		k++;
	}
	cout << "\n";
	/*
	int start = 0;
	deque<int> array(arr, arr + n);
	while (k <= n){
		int max = *max_element(array.begin() + start, array.begin() + k);
		cout << max << " ";
		start++;
		k++;
	}
	cout << "\n";
	*/
	/*
	while(k <= n){
		for (int i = start; i < k; i++){
			subarray.push_front(arr[i]);
		}
		start++;
		k++;
		int max = *max_element(subarray.begin(), subarray.end());
		cout << max << " ";
		subarray.clear();
	}
	cout << "\n";
	*/
	//Write your code here.
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t > 0){
		int n, k;
    	cin >> n >> k;
    	int i;
    	// int arr[n];
		int *arr = new int[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
		delete [] arr;
    	t--;
  	}
  	return 0;
}