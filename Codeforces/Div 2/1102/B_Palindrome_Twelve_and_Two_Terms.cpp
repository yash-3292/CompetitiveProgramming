#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    if(n%12 == 10){
        if(n < 22){
            cout << -1 << endl;
        } else{
            cout << 22 << " " << n-22 << endl;
        }
    } else{
        cout << n%12 << " " << n - (n%12) << endl;
    }
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