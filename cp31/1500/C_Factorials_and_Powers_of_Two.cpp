#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(int i, ll sum, int cnt, vector<ll>& fact, vector<pair<ll,int>>& comb){
    if(i == 16){
        comb.push_back({sum, cnt});
        return;
    }
    f(i+1, sum, cnt, fact, comb);
    f(i+1, sum+fact[i], cnt+1, fact, comb);
}

int main(){
    vector<ll> fact(16);
    fact[0] = 1;
    for(int i=1; i<16; i++) fact[i] = fact[i-1]*i;
    vector<pair<ll,int>> comb;
    f(0, 0, 0, fact, comb);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        int ans = INT_MAX;
        for(auto it : comb){
            if(it.first <= n){
                ll val = n-it.first;
                int temp = __builtin_popcountll(val);
                temp += it.second;
                ans = min(ans, temp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}