#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            int cnt = 0;
            if(arr[i][j] == '1') cnt++;
            if(arr[i+1][j] == '1') cnt++;
            if(arr[i][j+1] == '1') cnt++;
            if(arr[i+1][j+1] == '1') cnt++;
            if(cnt == 3){
                cout << "NO" << endl;
                return;
            }
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