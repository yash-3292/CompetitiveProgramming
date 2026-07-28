#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll a, b, c;
    cin >> a >> b >> c;
    if(a == b){
        cout << 0 << endl;
        return;
    }
    if(__gcd(a,c) == __gcd(b,c)){
        cout << 1 << endl;
        return;
    }
    if(__gcd(a,c+1) == __gcd(b,c+1)){
        cout << 2 << endl;
        return;
    }
    cout << 3 << endl;
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