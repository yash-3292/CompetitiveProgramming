#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int cnt = 1;
    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1]){
            cnt++;
            if(cnt >= m){
                cout << "NO" << endl;
                return;
            } 
        } else{
            cnt = 1;
        }
    }
    cout << "YES" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}