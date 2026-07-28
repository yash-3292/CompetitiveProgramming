#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, k;
    cin >> n >> k;
    string x, y;
    cin >> x >> y;
    string z;
    for(int i=0; i<n; i++){
        if(x[i] == '0' && y[i] == '1'){
            z += '1';
        } else if(x[i] == '1' && y[i] == '0'){
            z += '1';
        } else {
            z += '0';
        }
    }
    ll xzero = 0, yzero = 0, zzero = 0;
    for(ll i=0; i<n; i++){
        if(x[i] == '0') xzero++;
        if(y[i] == '0') yzero++;
        if(z[i] == '0') zzero++;
    }
    ll xnum, ynum, znum;
    ll total = (1LL<<k) + 1;
    if(k&1){
        xnum = total/3;
        ynum = total/3;
        znum = total/3;
        if(total%3 == 1){
            xnum++;
        } else if(total%3 == 2){
            xnum++;
            znum++;
        }
    } else{
        xnum = total/3;
        ynum = total/3;
        znum = total/3;
        if(total%3 == 1){
            xnum++;
        } else if(total%3 == 2){
            xnum++;
            ynum++;
        }
    }
    ll ans = 0;
    ans += xnum * xzero * (n - xzero);
    ans += ynum * yzero * (n - yzero);
    ans += znum * zzero * (n - zzero);
    cout << ans << endl;
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