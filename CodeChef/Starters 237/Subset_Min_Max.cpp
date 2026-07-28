#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        string s;
        cin >> s;
        vector<pair<ll,ll>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({a[i], s[i]-'0'});
        }
        sort(arr.begin(), arr.end());
        ll ans = 0;
        ll c = 0;
        ll mini = 0;
        ll maxi = 0;
        for(int i=n-1; i>=0; i--){
            if(arr[i].second){
                maxi = arr[i].first;
                break;
            }
        }
        for(int i=0; i<n; i++){
            if(arr[i].second){
                mini = arr[i].first;
                ll val = mini * maxi - c*x;
                ans = max(ans, val);
                c++;
                // cout << mini << " " << maxi << " " << c << endl;
            }
        }
        if(arr[n-1].second) c = 0;
        else c = 1;
        mini = 0;
        maxi = arr[n-1].first;
        arr[n-1].second = 1;
        for(int i=0; i<n; i++){
            if(arr[i].second){
                mini = arr[i].first;
                ll val = mini * maxi - c*x;
                ans = max(ans, val);
                c++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}