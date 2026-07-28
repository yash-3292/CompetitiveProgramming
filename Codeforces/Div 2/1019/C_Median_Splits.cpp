#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> temp(n);
    for(int i=0; i<n; i++){
        if(arr[i] <= k){
            temp[i] = -1;
        } else{
            temp[i] = 1;
        }
    }
    vector<int> pre(n), suf(n);
    pre[0] = temp[0];
    for(int i=1; i<n; i++) pre[i] = pre[i-1] + temp[i];
    suf[n-1] = temp[n-1];
    for(int i=n-2; i>=0; i--) suf[i] = suf[i+1] + temp[i];
    int maxi = INT_MIN;
    for(int i=0; i<n-1; i++){
        if(pre[i] <= 0){
            if(pre[i] <= maxi){
                cout << "YES" << endl;
                return;
            }
            maxi = max(maxi, pre[i]);
        }
    }
    maxi = INT_MIN;
    for(int i=n-1; i>=1; i--){
        if(suf[i] <= 0){
            if(suf[i] <= maxi){
                cout << "YES" << endl;
                return;
            }
            maxi = max(maxi, suf[i]);
        }
    }
    int i1 = -1;
    int j1 = -1;
    for(int i=0; i<n; i++){
        if(pre[i] <= 0){
            i1 = i;
            break;
        }
    }
    if(i1 == -1){
        cout << "NO" << endl;
        return;
    }
    for(int i=n-1; i>=0; i--){
        if(suf[i] <= 0){
            j1 = i;
            break;
        }
    }
    if(i1+1 < j1) cout << "YES" << endl;
    else cout << "NO" << endl;
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