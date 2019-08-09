//Reference: http://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
// Basically, the problem can be decomposed into maximum rectangle in a histogram problem.
// For each row, we calculate the maximum rectangle in the histogram where base of the histogram is
// current row. Height of the histogram for each row is calculated like cumulative sum.
#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

int maxHist(int row[]) { //Note: may require long long for larger inputs
    stack<int> result; // idea is to maintain non decreasing stack
    int top_val;
    int max_area = 0;
    int area = 0;
    int i=0;

    while(i<C) {
        if(result.empty() || row[result.top()] <= row[i]) // add to stack if current value is bigger or equal to the top
            result.push(i++);                             // or the stack is empty
        else {                           // otherwise keep removing items until current value is bigger or
            top_val = row[result.top()]; // equal to the top. Calculate area and update max every time.
            result.pop();
            area = top_val * i;
            if(!result.empty())
                area = top_val * (i-result.top()-1);
            max_area = max(area, max_area);
        }
    }

    while(!result.empty()) {            // process the remaining items in the stack in the same way.
        top_val = row[result.top()];    // it handles the cases from right to left.
        result.pop();
        area = top_val * i;
        if(!result.empty())
            area = top_val * (i-result.top()-1);
        max_area = max(area, max_area);
    }
    return max_area;
}

int maxRectangle(int A[][C]) {
    int result = maxHist(A[0]);
    for(int i=1; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(A[i][j]) A[i][j] += A[i-1][j]; // update height of the histogram for current row.
        }
        result = max(result, maxHist(A[i])); // determine maximum area of a rectangle in current histogram
    }
    return result;
}

int main() {
    int A[R][C] { {0, 1, 1, 0},
                 {1, 1, 1, 1},
                 {1, 1, 1, 1},
                 {1, 1, 0, 0} };

    cout << "Area of maximum rectangle is " << maxRectangle(A) << endl;

    return 0;
}
