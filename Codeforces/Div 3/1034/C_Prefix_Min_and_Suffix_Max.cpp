#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> preMin(n), sufMax(n);
    preMin[0] = arr[0];
    for(int i=1; i<n; i++) preMin[i] = min(preMin[i-1], arr[i]);
    sufMax[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--) sufMax[i] = max(sufMax[i+1], arr[i]);
    for(int i=0; i<n; i++){
        if(i == 0 || i == n-1){
            cout << 1;
            continue;
        }
        if(preMin[i-1] < arr[i] && arr[i] < sufMax[i+1]){
            cout << 0;
        } else{
            cout << 1;
        }
    }
    cout << endl;
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