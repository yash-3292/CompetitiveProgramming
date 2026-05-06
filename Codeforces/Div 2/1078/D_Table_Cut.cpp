#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> arr[i][j];
                if(arr[i][j]) cnt++;
            }
        }
        if(cnt&1){
            ll ans = (ll)(cnt/2+1)*(ll)(cnt/2);
            cout << ans << endl;
            cnt = cnt/2+1;
        } else{
            ll ans = (ll)(cnt/2)*(ll)(cnt/2);
            cout << ans << endl;
            cnt = cnt/2;
        }
        int val = 0;
        int x = -1;
        int y = -1;
        for(int i=0; i<n; i++){
            for(int j=m-1; j>=0; j--){
                if(arr[i][j]) val++;
                if(val == cnt){
                    x = i;
                    y = j;
                    break;
                }
            }
            if(x != -1) break;
        }
        for(int i=0; i<x; i++) cout << "D";
        for(int i=0; i<y; i++) cout << "R";
        cout << "D";
        for(int i=0; i<m-y; i++) cout << "R";
        for(int i=0; i<n-x-1; i++) cout << "D";
        cout << endl;
    }
    return 0;
}