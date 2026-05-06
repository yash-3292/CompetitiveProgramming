#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll val1, ll val2, ll a, ll b, ll c, ll d){
    return a < val1 && val1 <= c && b < val2 && val2 <= d;
}

pair<ll,ll> f(ll n, ll m, ll a, ll b, ll c, ll d){
    vector<ll> arr1;
    vector<ll> arr2;
    for(ll i=1; i*i<=n; i++){
        if(n%i == 0){
            arr1.push_back(i);
        }
    }
    for(ll i=1; i*i<=m; i++){
        if(m%i == 0){
            arr2.push_back(i);
        }
    }
    for(auto i : arr1){
        for(auto j : arr2){
            if(check(i*j, (n/i)*(m/j), a, b, c, d)) return {i*j, (n/i)*(m/j)};
            if(check(i*(m/j), (n/i)*j, a, b, c, d)) return {i*(m/j), (n/i)*j};
            if(check((n/i)*(m/j), i*j, a, b, c, d)) return {(n/i)*(m/j), i*j};
            if(check((n/i)*j, i*(m/j), a, b, c, d)) return {(n/i)*j, i*(m/j)};
        }
    }
    return {-1,-1};
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        pair<ll,ll> val1, val2, val3, val4;
        val1 = f(a,b,a,b,c,d);
        val2 = f(a*2,b,a,b,c,d);
        val3 = f(a,b*2,a,b,c,d);
        val4 = f(a*2,b*2,a,b,c,d);
        if(val1.first != -1){
            cout << val1.first << " " << val1.second << endl;
            continue;
        }
        if(val2.first != -1){
            cout << val2.first << " " << val2.second << endl;
            continue;
        }
        if(val3.first != -1){
            cout << val3.first << " " << val3.second << endl;
            continue;
        }
        if(val4.first != -1){
            cout << val4.first << " " << val4.second << endl;
            continue;
        }
        cout << -1 << " " << -1 << endl;
    }
    return 0;
}