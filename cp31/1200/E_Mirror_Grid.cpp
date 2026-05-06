#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<char>> arr(n, vector<char>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }
        int ans = 0;
        for(int i=0; i<(n+1)/2; i++){
            for(int j=0; j<n/2; j++){
                int cnt = 0;
                if(arr[i][j] == '1') cnt++;
                if(arr[n-1-j][i] == '1') cnt++;
                if(arr[n-1-i][n-1-j] == '1') cnt++;
                if(arr[j][n-1-i] == '1') cnt++;
                cnt = min(cnt, 4-cnt);
                ans += cnt;
            }
        }
        cout << ans << endl;
    }
    return 0;
}