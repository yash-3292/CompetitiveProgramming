#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, l, r, k;
        cin >> n >> l >> r >> k;
        if(n&1){
            cout << l << endl;
            continue;
        }
        if(n == 2){
            cout << -1 << endl;
            continue;
        }
        ll next = 2;
        while(next < l) next *= (ll)2;
        if(next >= l && next <= r){
            if(k <= n-2){
                cout << l << endl;
            } else{
                cout << next << endl;
            }
        } else{
            cout << -1 << endl;
            continue;
        }
    }
    return 0;
}