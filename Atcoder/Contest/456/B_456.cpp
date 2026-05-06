#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n = 3;
    int m = 6;
    vector<vector<int>> cnt(n, vector<int>(m+1));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x;
            cin >> x;
            cnt[i][x]++;
        }
    }
    double ans = (double)1/(double)216; 
    double val = 0; 
    for(int i=4; i<=6; i++){
        for(int j=4; j<=6; j++){
            for(int k=4; k<=6; k++){
                if(i != j && j != k && k != i){
                    val += cnt[0][i] * cnt[1][j] * cnt[2][k];
                }
            }
        }
    }
    ans = ans * (double) val;
    cout << setprecision(10) << ans << endl;
    return 0;
}