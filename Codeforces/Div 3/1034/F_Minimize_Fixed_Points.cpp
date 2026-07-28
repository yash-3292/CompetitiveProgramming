#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 1e5+10;
bool prime[maxN];

void pre(){
    prime[0] = prime[1] = false;
    for(int i=2; i<maxN; i++) prime[i] = true;
    for(int i=2; i*i<maxN; i++){
        if(prime[i]){
            for(int j=i*i; j<maxN; j+=i){
                prime[j] = false;
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> p;
    for(int i=n; i>=0; i--) if(prime[i]) p.push_back(i);
    vector<int> ans(n+1);
    for(int i=0; i<=n; i++) ans[i] = i;
    vector<vector<int>> arr;
    unordered_map<int,int> vis;
    for(auto it : p){
        vector<int> temp;
        for(int i=it; i<=n; i+=it){
            if(vis.find(i) == vis.end()){
                temp.push_back(i);
                vis[i] = 1;
            } 
        }
        arr.push_back(temp);
    }
    for(auto a : arr){
        int sz = a.size();
        for(int i=0; i<sz; i++){
            ans[a[i]] = a[(i+1)%sz];
        }
    }
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pre();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}