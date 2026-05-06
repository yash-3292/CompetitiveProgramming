#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(double mid, vector<int>& x, vector<int>& t, double& ans){
    double l = -1*(double)1e18;
    double r = double(1e18);
    int n = x.size();
    for(int i=0; i<n; i++){
        if(mid > (double)t[i]) l = max(l, (double)x[i]-(mid-(double)t[i]));
        else l = max(l, (double)x[i]);
        if(mid > (double)t[i]) r = min(r, (double)x[i]+(mid-(double)t[i]));
        else r = min(r, (double)x[i]);
    }
    if(l<=r){
        ans = (l+r)/2.0;
        return true;
    } else{
        return false;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> x(n), t(n);
        for(int i=0; i<n; i++) cin >> x[i];
        for(int i=0; i<n; i++){
            cin >> t[i];
        }
        double lo = 0;
        double hi = INT_MAX;
        double ans;
        for(int i=0; i<100; i++){
            double mid = lo + (hi-lo)/(double)2;
            if(check(mid,x,t,ans)){
                hi = mid;
            } else{
                lo = mid;
            }
        }
        check(hi,x,t,ans);
        cout << fixed << setprecision(10) << ans << "\n";
    }
    return 0;
}