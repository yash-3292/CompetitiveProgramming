#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;

ll sumn(ll n){
    return (n * (n+1)) / 2;
}

ll sum(ll l, ll r){
    ll ans = sumn(r);
    if(l > 0) ans -= sumn(l-1);
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    ll initial = 0;
    for(int i=0; i<n; i++){
        initial += (ll)arr[i] * (ll)i;
    }
    ll finall = 0;
    vector<int> row(n);
    for(int i=0; i<n; i++){
        row[arr[i]-1]++;
    }
    for(int i=n-2; i>=0; i--){
        row[i] += row[i+1];
    }
    for(int i=0; i<n; i++){
        finall += sum(n-row[i], n-1);
    }
    ll ans = finall - initial;
    ordered_set s;
    int timer = 0;
    int maxi = 0;
    for(int i=0; i<n; i++){
        int x = s.order_of_key({arr[i], 0});
        maxi = max(maxi, i-x);
        s.insert({arr[i], timer});
        timer++;
    }
    ans += (ll)maxi;
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}