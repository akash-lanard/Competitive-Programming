#include <bits/stdc++.h>
using namespace std;

///............................isleap............................

#include <bits/stdc++.h>
using namespace std;

int isleap(int y)
{
    return y%4==0 && (y%100 != 0 || y%400 == 0);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", isleap(n));
    return 0;
}

///......................................................................

///............................day of week............................

int isleap(int y)
{
    return y%4==0 && (y%100 != 0 || y%400 == 0);
}

int dayOfWeek(int year, int month, int day)
{
    int init_y, init_m = 1, init_d = 1, init_DOW = 3, cnt=0;

    for(init_y=1 ; init_y<year; init_y++) {
        if(isleap(init_y)) cnt += 366;
        else cnt += 365;
    }
    for(init_m=1; init_m<month; init_m++) {
        if(init_m == 1 || init_m == 3 || init_m == 5 || init_m == 7 || init_m == 8 || init_m == 10 || init_m == 12) {
            cnt += 31;
        }
        else if(init_m == 4 || init_m == 6 || init_m == 9 || init_m == 11) {
            cnt += 30;
        }
        else if(init_m == 2 && isleap(year)==1) {
            cnt += 29;
        }
        else if(init_m == 2 && isleap(year)==0) {
            cnt += 28;
        }
    }
    for(init_d=1; init_d<day; init_d++) {
        cnt++;
    }
    long long ret = (cnt+3)%7;
    return ret;
}

int main()
{
    cout << dayOfWeek(2010, 8, 9) << endl;
    return 0;
}

///......................................................................

///.....................all possible subsets............................

int main()
{
    int p[20], N=20;
    for(int i=0; i<N; i++) p[i] = i;

    for(int i=0; i < (1<<N); i++) {
        for(int j=0; j<N; j++) {
            if(i &(1<<j)) {
                printf("%d ", p[j]);
            }
        }
        printf("\n");
        system("PAUSE");
    }
    return 0;
}

///......................................................................

///.....................all possible permutations............................

int main()
{
    int p[10], N = 10;
    for(int i=0; i<N; i++) {
        p[i] = i;
    }
    do {
        for(int i=0; i<N; i++) printf("%c ", 'A'+p[i]);
        printf("\n");
    } while(next_permutation(p, p+N));

    return 0;
}

///......................................................................

///.....................Longest continuous time and idle time............................

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int> > v;
    for(int i=0; i<n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, -1));  //swap 1 and -1 if ending time
        v.push_back(make_pair(b, 1));   //needs to come first at a specific time
    }
    sort(v.begin(), v.end());

    /*for(int i=0; i<v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }*/

    int LCT=0, LIT=0, cnt=0;
    int ssstart, ssend, flag=0;
    for(int i=0; i<v.size(); i++) {
        if(i==0) {
            ssstart = v[0].first;
            cnt++;
            flag = 1;
        }
        else {
            if(v[i].second==-1) cnt++;
            else if(v[i].second==1) cnt--;
            if(cnt==0 && flag==1) {
                ssend = v[i].first;
                if((ssend-ssstart)>LCT) {
                    LCT = (ssend-ssstart);
                }
                ssstart = v[i].first;
                flag = 0;
            }
            else if(cnt==1 && flag==0) {
                ssend = v[i].first;
                if((ssend-ssstart)>LIT) {
                    LIT = (ssend-ssstart);
                }
                ssstart = v[i].first;
                flag = 1;
            }
        }
    }

    cout << LCT << " " << LIT << endl;

    return 0;
}

///......................................................................

///............................Sample min max deque............................

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        int n, d;
        scanf("%d %d", &n, &d);
        int ara_mx[n+5], ara_mn[n+5];
        deque<pair<int, int> > dq_mx, dq_mn;
        for(int j=0; j<n; j++) {
            int x;
            scanf("%d", &x);
            pair<int, int> p;
            p = make_pair(j, x);
            //mx
            if(dq_mx.size()==0 || x<dq_mx.back().second) {
                dq_mx.push_back(p);
            }
            else {
                while(dq_mx.size()!=0 && x>=dq_mx.back().second) {
                    dq_mx.pop_back();
                }
                dq_mx.push_back(p);
            }
            deque<pair<int, int> >::iterator it;
            for(it=dq_mx.begin(); it!=dq_mx.end(); ++it) {
                if(j-dq_mx.front().first>=d) {
                    dq_mx.pop_front();
                }
            }
            ara_mx[j] = dq_mx.front().second;
            //mx

            //mn
            if(dq_mn.size()==0 || x>dq_mn.back().second) {
                dq_mn.push_back(p);
            }
            else {
                while(dq_mn.size()!=0 && x<=dq_mn.back().second) {
                    dq_mn.pop_back();
                }
                dq_mn.push_back(p);
            }
            for(it=dq_mn.begin(); it!=dq_mn.end(); ++it) {
                if(j-dq_mn.front().first>=d) {
                    dq_mn.pop_front();
                }
            }
            ara_mn[j] = dq_mn.front().second;
            //mn
        }
        int mx_dif=-1;
        for(int j=0; j<n; j++) {
            if(ara_mx[j]-ara_mn[j]>mx_dif) mx_dif = ara_mx[j]-ara_mn[j];
        }
        printf("Case %d: %d\n", i+1, mx_dif);
    }
    return 0;
}

///......................................................................

///.....................Maximum size rectangle binary sub-matrix with all 1s............................

#define R 4
#define C 4

int maxHist(int row[])
{
    stack<int> result;
    int top_val;
    int max_area = 0;
    int area = 0;
    int i=0;

    while(i<C) {
        if(result.empty() || row[result.top()] <= row[i])
            result.push(i++);
        else {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
            if(!result.empty())
                area = top_val * (i-result.top()-1);
            max_area = max(area, max_area);
        }
    }

    while(!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if(!result.empty())
            area = top_val * (i-result.top()-1);
        max_area = max(area, max_area);
    }
    return max_area;
}

int maxRectangle(int A[][C])
{
    int result = maxHist(A[0]);
    for(int i=1; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(A[i][j]) A[i][j] += A[i-1][j];
        }
        result = max(result, maxHist(A[i]));
    }
    return result;
}

int main()
{
    int A[R][C] { {0, 1, 1, 0},
                 {1, 1, 1, 1},
                 {1, 1, 1, 1},
                 {1, 1, 0, 0} };

    cout << "Area of maximum rectangle is " << maxRectangle(A) << endl;

    return 0;
}

///......................................................................

///.....................Largest rectangle in a histogram............................

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

///......................................................................

///.....................Largest Sum Contiguous Subarray(Kadane’s Algorithm)............................

int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];

   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
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

///......................................................................

///.....................Maximum Product Subarray............................

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

///......................................................................

///.....................Disjoint set............................

#define SIZE 105

int parent[SIZE];

void makeset(int u)
{
    parent[u] = u;
}

void init_disjoint_set(int N)
{
    for(int i=0; i<=N; i++) {
        makeset(i);
    }
}

/*int FindRepresentative(int r)   //without path compression
{
    if(parent[r]==r) {
        return r;
    }
    return FindRepresentative(parent[r]);
}*/

int FindRepresentative(int r)   //with path compression
{
    if(parent[r]==r) {
        return r;
    }

    parent[r] = FindRepresentative(parent[r]);

    return parent[r];
}

void Union(int a, int b)
{
    int u = FindRepresentative(a);
    int v = FindRepresentative(b);

    if(u!=v) {
        parent[u] = v;
    }
}

int main()
{
    #ifdef forthright48
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // forthright48

    int n, m;
    scanf("%d %d", &n, &m);

    init_disjoint_set(n);

    for(int i=0; i<m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        Union(u, v);
    }

    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        int x = FindRepresentative(u);
        int y = FindRepresentative(v);

        if(x==y) {
            printf("%d and %d are from the same set\n", u, v);
            printf("Representative(%d) = %d, Representative(%d) = %d\n\n", u, x, v, y);
        }
        else {
            printf("%d and %d are from the different sets\n", u, v);
            printf("Representative(%d) = %d, Representative(%d) = %d\n\n", u, x, v, y);
        }
    }

    return 0;
}

///......................................................................
///......................END OF TEMPLATE...................................
