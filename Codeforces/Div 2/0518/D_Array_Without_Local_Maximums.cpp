#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<vector<ll>> next(201, vector<ll>(3,0));
    vector<vector<ll>> curr(201, vector<ll>(3,0));

    for(int prev=1; prev<=200; prev++){
        for(int c=0; c<3; c++){
            if(c == 2) next[prev][c] = 0;
            else next[prev][c] = 1;
        }
    }

    for(int i=n-1; i>=1; i--){
        
        for(int prev=1; prev<=200; prev++){
            for(int c=0; c<3; c++){
                next[prev][c] += next[prev-1][c]; 
            }
        }

        for(int prev=1; prev<=200; prev++){
            for(int c=0; c<3; c++){
                ll ans = 0;
                if(arr[i] != -1){
                    if(c == 2 && prev > arr[i]) ans = 0;
                    else{
                        int nc;
                        if(prev > arr[i]) nc = 0;
                        else if(prev == arr[i]) nc = 1;
                        else nc = 2;

                        ans = (next[arr[i]][nc] - next[arr[i]-1][nc] + mod) % mod;
                    }
                } else{
                    if(c == 0 || c == 1){
                        ans = (ans + (next[prev-1][0] - next[0][0] + mod) % mod) % mod;
                    }
                    ans = (ans + (next[prev][1] - next[prev-1][1] + mod)) % mod;
                    ans = (ans + (next[200][2] - next[prev][2] + mod) % mod) % mod;
                }

                curr[prev][c] = ans;
            }
        }
        next = curr;
    }

    ll ans = 0;
    if(arr[0] != -1){
        ans = curr[arr[0]][2];
    } else{
        for(int j=1; j<=200; j++){
            ans = (ans + curr[j][2]) % mod;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}