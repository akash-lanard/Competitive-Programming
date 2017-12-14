#include <bits/stdc++.h>
using namespace std;

int maxProduct(int ara[], int n)
{
    int max_so_far = INT_MIN;
    int max_ending_here = ara[0];
    int min_ending_here = ara[0];

    for(int i=1; i<n; i++) {
        if(ara[i]==0) {
            max_so_far = max(max_so_far, 0);
            continue;
        }
        if(ara[i-1]==0) {
            max_ending_here = min_ending_here = ara[i];
            max_so_far = max_ending_here > max_so_far ? max_ending_here : max_so_far;
            continue;
        }

        int temp = max_ending_here;
        max_ending_here = max(max(max_ending_here*ara[i], min_ending_here*ara[i]), ara[i]);
        min_ending_here = min(min(temp*ara[i], min_ending_here*ara[i]), ara[i]);

        max_so_far = max_ending_here > max_so_far ? max_ending_here : max_so_far;
    }

    return max_so_far;
}

int main()
{
    int arr[] = {-1,-3,-4}; // expected 12
	int n =  sizeof(arr)/sizeof(arr[0]);
	cout << "res = ";
	cout << maxProduct(arr, n) << endl;

	int arr1[] = {1, -2, -3, 0, 7, -8, -2}; // expected 112
	n =  sizeof(arr1)/sizeof(arr1[0]);
	cout << "res = ";
	cout << maxProduct(arr1, n) << endl;

	int arr2[] = {0,0,0,0,0}; // expected 0
	n =  sizeof(arr2)/sizeof(arr2[0]);
	cout << "res = ";
	cout << maxProduct(arr2, n) << endl;

	int arr3[] = {0,0,-3,0,0}; // expected 0
	n =  sizeof(arr3)/sizeof(arr3[0]);
	cout << "res = ";
	cout << maxProduct(arr3, n) << endl;

	return 0;
}
