#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> arr[i][j];
    }
    int sum = 0;
    for(int j=0; j<m; j++){
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, arr[i][j]);
        }
        sum += maxi;
    }
    cout << sum << endl;
    return 0;
}