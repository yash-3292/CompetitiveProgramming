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
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x;
                cin >> x;
                arr[i][j] = x-1;
            }
        }
        map<ll, int> mpp;
        for(int i=0; i<n; i++){
            vector<int> temp(m);
            for(int j=0; j<m; j++){
                temp[arr[i][j]] = j;
            }
            ll val = 0;
            for(int j=0; j<m; j++){
                val = val*10 + (ll)(temp[j]+1);
                // cout << val << " ";
                mpp[val] = 1;
            }
        }
        // cout << endl;
        for(int i=0; i<n; i++){
            ll val = 0;
            int j;
            for(j=0; j<m; j++){
                val = val*10 + (ll)(arr[i][j]+1);
                if(mpp.find(val) == mpp.end()) break;
                // cout << val << " ";
            }
            cout << j << " ";
        }
        // cout << endl;
        cout << endl;
    }
    return 0;
}