#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int mid, int k, string s, vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i] <= mid){
            s[i] = 'G';
        }
    }
    if(s[0] == 'G'){
        s[0] = 'R';
    }
    int val = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'B'){
            if(i == 0 || s[i-1] != 'B'){
                val++;
            }
        } else if(s[i] == 'G'){
            if(i != 0 && s[i-1] == 'B'){
                s[i] = 'B';
            }
        }
    }
    return val <= k;
}

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int l = 0;
    int r = 1e9;
    int ans = -1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(check(mid, k, s, arr)){
            ans = mid;
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
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