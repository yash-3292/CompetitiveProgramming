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
                cin >> arr[i][j];
            }
        }
        ll total = 0;
        for(int j=0; j<m; j++){
            vector<int> a(n);
            for(int i=0; i<n; i++) a[i] = arr[i][j];
            sort(a.begin(), a.end());
            ll sum = (ll)a[0];
            for(int i=1; i<n; i++){
                total += (ll)i * (ll)a[i] - sum;
                sum += (ll)a[i];
            } 
        }
        cout << total << endl;
    }
    return 0;
}