#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> next(n);
    unordered_map<int,int> mpp;
    for(int i=n-1; i>=0; i--){
        if(mpp.find(a[i]) == mpp.end()) next[i] = -1;
        else next[i] = mpp[a[i]];
        mpp[a[i]] = i;
    }
    for(int i=0; i<n; i++){
        pq.push({i});
    }
    int j = 0;
    while(j < n){
        if(pq.empty()){
            cout << "NO" << endl;
            return;
        }
        int ind = pq.top();
        int val = a[ind];
        pq.pop();
        if(val == b[j]){
            j++;
        } else{
            if(next[ind] == -1){
                cout << "NO" << endl;
                return;
            } else{
                pq.push({next[ind]});
            }
        }
    }
    cout << "YES" << endl;
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