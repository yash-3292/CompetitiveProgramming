#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int mid, int n, int m, int k){
    mid--;
    int x = mid/2;
    int y = mid-x;
    int lim = min(k-1, n-k);
    if(x > lim){
        x = lim;
        y = mid-x;
    }
    int val = y + y-1 + x;
    return (val <= m);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int l = 1;
        int r = n;
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(mid, n, m, k)){
                ans = mid;
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}