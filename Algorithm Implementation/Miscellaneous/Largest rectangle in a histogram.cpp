// Reference: https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

#include <bits/stdc++.h>
using namespace std;

int findMaxArea(int ara[], int n)  { //Note: may require long long for larger inputs
    stack<int> s; // idea is to maintain non decreasing stack
    int i=0;
    int maxArea = 0;
    while(i<n) {
        if(s.empty() || ara[s.top()]<=ara[i]) {
            s.push(i++); // add to stack if current value is bigger or equal to the top
        }                // or the stack is empty
        else {
            int top_indx = s.top(); // otherwise keep removing items until current value is bigger or
            s.pop();                // equal to the top. Calculate area and update max every time.
            int area = ara[top_indx]*(s.empty() ? i : i-s.top()-1);
            if(area>maxArea) maxArea = area;
        }
    }

    while(!s.empty()) {             // process the remaining items in the stack in the same way.
        int top_indx = s.top();     // it handles the cases from right to left.
        s.pop();
        int area = ara[top_indx]*(s.empty() ? i : i-s.top()-1);
        if(area>maxArea) maxArea = area;
    }

    return maxArea;
}

int main() {
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
