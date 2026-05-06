#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, vector<int>& arr, vector<int>& vis, string &s, string& t){
    vis[node] = 1;
    t += s[node];
    if(!vis[arr[node]]){
        dfs(arr[node], arr, vis, s, t);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++) arr[i]--;
        vector<int> vis(n, 0);
        ll ans = 1;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                string t;
                dfs(i, arr, vis, s, t);
                int m = t.size();
                ll val = m;
                for(int j=1; j<m; j++){
                    if(m%j == 0){
                        int flag = 1;
                        for(int k=0; k<m; k++){
                            if(t[k] != t[(k+j)%m]){
                                flag = 0;
                                break;
                            }
                        }
                        if(flag){
                            val = j;
                            break;
                        }
                    }
                }
                ans = ans * (val / __gcd(ans, val));
            }
        }
        cout << ans << endl;
    }
    return 0;
}