#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(ll i, vector<vector<ll>>& arr, vector<ll>& ind, priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>>& pq){
    ll j = ind[i];
    ll n = arr[i].size();
    ll sum = 0;
    ll thres = 0;
    while(j < n){
        sum += arr[i][j];
        j++;
        thres = max(thres, -1*sum);
        if(sum >= 0){
            ind[i] = j;
            pq.push({thres, sum, i});
            return;
        }
    }
}

void solve(){
    ll x, k;
    cin >> x >> k;
    vector<vector<ll>> arr;
    for(ll i=0; i<k; i++){
        ll n;
        cin >> n;
        vector<ll> temp(n);
        for(ll i=0; i<n; i++) cin >> temp[i];
        arr.push_back(temp);
    } 
    vector<ll> ind(k,0);
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    for(ll i=0; i<k; i++){
        f(i, arr, ind, pq);
    }
    while(!pq.empty()){
        auto vec = pq.top();
        pq.pop();
        ll thres = vec[0];
        ll val = vec[1];
        ll i = vec[2];
        if(thres > x) break;
        x += val;
        f(i, arr, ind, pq);
    }
    cout << x << endl;
}

int main(){
    solve();
    return 0;
}