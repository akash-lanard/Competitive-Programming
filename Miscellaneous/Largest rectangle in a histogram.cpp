#include <bits/stdc++.h>
using namespace std;

int findMaxArea(int ara[], int n) //Note: may require long long for larger inputs
{
    stack<int> s;
    int i=0;
    int maxArea = 0;
    while(i<n) {
        if(s.empty() || ara[s.top()]<=ara[i]) {
            s.push(i++);
        }
        else {
            int top_indx = s.top();
            s.pop();
            int area = ara[top_indx]*(s.empty() ? i : i-s.top()-1);
            if(area>maxArea) maxArea = area;
        }
    }

    while(!s.empty()) {
        int top_indx = s.top();
        s.pop();
        int area = ara[top_indx]*(s.empty() ? i : i-s.top()-1);
        if(area>maxArea) maxArea = area;
    }

    return maxArea;
}

int main()
{
    while(1) {
        int n;
        scanf("%d", &n);
        if(!n) break;
        int ara[n];
        for(int i=0; i<n; i++) {
            scanf("%d", &ara[i]);
        }

        printf("%d\n", findMaxArea(ara, n));
    }

    return 0;
}
