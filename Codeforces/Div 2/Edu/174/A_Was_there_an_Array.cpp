#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    n-=2;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=1; i<n-1; i++){
        if(arr[i-1] == 1 && arr[i] == 0 && arr[i+1] == 1){
            cout << "NO" << endl;
            return;
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