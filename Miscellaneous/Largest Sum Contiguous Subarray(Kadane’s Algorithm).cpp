//Reference: http://www.geeksforgeeks.org/?p=576
#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int sz)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    int strt=0, e=0, s=0;

    for(int i=0; i<sz; i++) {
        max_ending_here += a[i];
        if(max_ending_here < 0) {
            max_ending_here = 0;
            s = i+1;
        }
        else if(max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            strt = s;
            e = i;
        }
    }
    /*cout << "Maximum contiguous sum is " << max_so_far << endl;
    cout << "Starting index "<< strt << endl
    << "Ending index "<< e << endl;*/
    return max_so_far;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    return 0;
}
