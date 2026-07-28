#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll,ll> perfectSquare;

void f(){
    for(ll i=1; i<=1e6; i++){
        perfectSquare[i*i] = 1;
    }
}

void solve(){
    ll n;
    cin >> n;
    ll sum = 0;
    ll i = 1;
    vector<ll> ans;
    while(i <= n){
        if(perfectSquare.find(sum+i) != perfectSquare.end()){
            if(i == n){
                cout << -1 << endl;
                return;
            }
            ans.push_back(i+1);
            ans.push_back(i);
            sum += i+1;
            sum += i;
            i += 2;
        } else{
            ans.push_back(i);
            sum += i;
            i++;
        }
    }
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    f();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}