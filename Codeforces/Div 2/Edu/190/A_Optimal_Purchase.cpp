#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll group = min(3*a, b);
    ll cost = (n/3)*group;
    n = n%3;
    cost += min(group, n*a);
    cout << cost << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}