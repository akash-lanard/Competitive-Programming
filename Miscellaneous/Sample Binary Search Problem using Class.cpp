#include <bits/stdc++.h>
using namespace std;

class FairWorkload {
    vector<int> v;
    int n;
    bool OK(int cost, int workers) {
        int sum=0, cnt=1;
        for(int i=0; i<n; i++) {
            if(sum+v[i]>cost) return false;
            else {
                sum += v[i];
                if(i!=n-1 && sum+v[i+1]>cost) {
                    sum = 0;
                    cnt++;
                }
            }
        }
        if(cnt>workers) return false;
        return true;
    }
public:
    int getMostWork(vector<int> folders, int workers);
};

int FairWorkload::getMostWork(vector<int> folders, int workers)
{
    v = folders;
    n = folders.size();
    int mx = 0;
    int sum = 0;
    for(int i=0; i<n; i++) {
        if(v[i]>mx) mx = v[i];
        sum += v[i];
    }
    int low = mx;
    int high = sum;
    int mid;
    int cost = -1;

    while(low<=high) {
        mid = (low+high)/2;
        if(OK(mid, workers)) {
            cost = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return cost;
}
