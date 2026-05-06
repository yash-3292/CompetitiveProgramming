#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

ll dfs(int node, vector<int>& l, vector<int>& r, vector<ll>& arr){
    if(l[node] == 0) return 0;
    ll ans = dfs(l[node], l, r, arr) + dfs(r[node], l, r, arr) + 4;
    ans = ans % mod;
    arr[node] = ans;
    return ans;
}

void dfs1(int node, ll val, vector<int>& l, vector<int>& r, vector<ll>& arr, vector<ll>& ans){
    ll num = (val + arr[node])%mod;
    ans[node] = num;
    if(l[node] == 0) return;
    dfs1(l[node], num+1, l, r, arr, ans);
    dfs1(r[node], num+1, l, r, arr, ans);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> l(n+1), r(n+1);
        for(int i=1; i<=n; i++) cin >> l[i] >> r[i];
        vector<ll> arr(n+1, 0);
        dfs(1, l, r, arr);
        vector<ll> ans(n+1);
        dfs1(1, 1, l, r, arr, ans);
        for(int i=1; i<=n; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}