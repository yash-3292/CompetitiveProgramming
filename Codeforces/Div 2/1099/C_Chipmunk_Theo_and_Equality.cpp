#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    unordered_map<int,int> mpp;
    vector<int> dis1(n);
    vector<int> dis2(n);
    for(int i=0; i<n; i++){
        int x = arr[i];
        int cnt = 0;
        while(x > 2){
            cnt++;
            mpp[x]++;
            if(x&1){
                x++;
            } else{
                x /= 2;
            }
        }
        if(x == 1){
            dis1[i] = cnt;
            dis2[i] = cnt+1;
        } else{
            dis1[i] = cnt+1;
            dis2[i] = cnt;
        }
    }
    ll val1 = 0, val2 = 0;
    for(auto it : dis1) val1 += (ll)it;
    for(auto it : dis2) val2 += (ll)it;
    ll ans = min(val1, val2);
    int maxi = 2;
    int secmaxi = 1;
    for(auto it : mpp){
        if(it.second == n){
            int val = it.first;
            if(val >= maxi){
                secmaxi = maxi;
                maxi = val;
            } else if(val >= secmaxi){
                secmaxi = val;
            }
        }
    }
    ll val3 = 0, val4 = 0;
    for(int i=0; i<n; i++){
        int x = arr[i];
        int cnt = 0;
        while(x != maxi){
            cnt++;
            if(x&1){
                x++;
            } else{
                x /= 2;
            }
        }
        val3 += cnt;
    }
    for(int i=0; i<n; i++){
        int x = arr[i];
        int cnt = 0;
        while(x != secmaxi){
            cnt++;
            if(x&1){
                x++;
            } else{
                x /= 2;
            }
        }
        val4 += cnt;
    }
    ans = min(ans, val3);
    ans = min(ans, val4);
    cout << ans << endl;
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