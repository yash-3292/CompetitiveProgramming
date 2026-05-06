#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> arr(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> arr[i][j];
            }
        }
        ll difference = 0;
        vector<string> s(n);
        for(int i=0; i<n; i++){
            cin >> s[i];
        }
        vector<vector<int>> preSum(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(s[i][j] == '1'){
                    difference += (ll)arr[i][j];
                    preSum[i][j] = 1;
                } else{
                    difference -= (ll)arr[i][j];
                    preSum[i][j] = -1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                preSum[i][j] += preSum[i][j-1];
            }
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                preSum[i][j] += preSum[i-1][j];
            }
        }
        int gcd = -1;
        for(int i=0; i+k-1<n; i++){
            for(int j=0; j+k-1<m; j++){
                int val = preSum[i+k-1][j+k-1];
                if(j>0){
                    val -= preSum[i+k-1][j-1];
                }
                if(i > 0){
                    val -= preSum[i-1][j+k-1];
                }
                if(i > 0 && j > 0){
                    val += preSum[i-1][j-1];
                }
                val = abs(val);
                if(val == 0) continue;
                if(gcd == -1){
                    gcd = val;
                } else{
                    gcd = __gcd(gcd, val);
                }
            }
        }
        difference = abs(difference);
        // cout << difference << " " << gcd << "   ";
        if(gcd == -1 && difference > 0){
            cout << "NO" << endl;
            continue;
        }
        if(difference%(ll)gcd == 0){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}