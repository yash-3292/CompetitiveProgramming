#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll x, y;
    cin >> x >> y;
    if(y/x > 2){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}