#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                ans++;
            }
        }
    }
    for(int i=0; i<n; i++){
        int val = 0;
        for(int j=0; j<n; j++){
            if(arr[j] > arr[i]){
                if(j < i) val--;
                else if(j > i) val++;
            }
        }
        if(val < 0) ans += val;
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