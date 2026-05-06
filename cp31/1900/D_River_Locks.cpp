#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    ll thres = 0;
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum += (ll)arr[i];
        ll ind = i+1;
        ll val = sum/ind;
        if(sum%ind != 0) val++;
        thres = max(thres, val);
    }
    int q;
    cin >> q;
    while(q--){
        ll t;
        cin >> t;
        if(t < thres){
            cout << -1 << endl;
            continue;
        }
        ll ans = sum / t;
        if(sum%t != 0) ans++;
        cout << ans << endl;
    }
    return 0;
}