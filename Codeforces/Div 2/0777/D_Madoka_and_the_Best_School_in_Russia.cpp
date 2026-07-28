#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll x, d;
    cin >> x >> d;
    if(x % (d*d) != 0){
        cout << "NO" << endl;
        return;
    }
    x /= (d*d);
    
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