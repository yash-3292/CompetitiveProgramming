#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(ll i, ll n, int& ans){
    if(i <= n){
        ans++;
        f(i*10, n, ans);
        f(i*10+1, n, ans);
    }
}

int main(){
    ll n;
    cin >> n;
    
    int ans = 0;
    f(1, n, ans);
    cout << ans << endl;
    return 0;
}