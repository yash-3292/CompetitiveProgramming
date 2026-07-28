#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(ll x, ll y, ll a, ll b, ll c, ll d){
    if(x <= a) x = (a/x)*x + x;
    if(y <= b) y = (b/y)*y + y;
    if(x <= c && y <= d){
        cout << x << " " << y << endl;
        return true;
    }
    return false;
}

void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<pair<ll,ll>> arr1;
    vector<pair<ll,ll>> arr2;
    for(int i=1; i*i<=a; i++){
        if(a%i == 0){
            arr1.push_back({i, a/i});
        }
    }
    for(int i=1; i*i<=b; i++){
        if(b%i == 0){
            arr2.push_back({i, b/i});
        }
    }
    for(auto it1 : arr1){
        for(auto it2 : arr2){
            ll p1 = it1.first;
            ll p2 = it1.second;
            ll q1 = it2.first;
            ll q2 = it2.second;
            if(f(p1*p2, q1*q2, a, b, c, d)) return;
            if(f(p1*q1, p2*q2, a, b, c, d)) return;
            if(f(p1*q2, p2*q1, a, b, c, d)) return;
            if(f(q1*q2, p1*p2, a, b, c, d)) return;
            if(f(p2*q2, p1*q1, a, b, c, d)) return;
            if(f(p2*q1, p1*q2, a, b, c, d)) return;
        }
    }
    cout << -1 << " " << -1 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}