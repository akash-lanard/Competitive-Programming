#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(1) {
        scanf("%d", &n);
        if(n==0) break;

        //start
        int temp = n;
        while(temp>=10) {
            int sum=0;
            while(temp>0) {
                int rem = temp%10;
                sum += rem;
                temp /= 10;
            }
            temp = sum;
        }
        //end
        
        printf("%d\n", temp);
    }
    return 0;
}
