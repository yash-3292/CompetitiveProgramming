#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n = 2023;
    vector<vector<ll>> a(n, vector<ll>(n, 0));
    vector<vector<ll>> b(n, vector<ll>(n, 0));
    int sz = n*(n+1)/2;
    vector<pair<int,int>> mpp(sz+10);
    ll val = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            ll sq = val*val;
            b[i][j] += sq;
            mpp[val] = {i,j};
            val++;
        }
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<=i; j++){
            b[i+1][j] += b[i][j];
            a[i+1][j+1] += a[i][j] + b[i][j];
        }
    }
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int i = mpp[x].first;
        int j = mpp[x].second;
        ll ans = a[i][j] + b[i][j];
        cout << ans << endl;
    }
    return 0;
}