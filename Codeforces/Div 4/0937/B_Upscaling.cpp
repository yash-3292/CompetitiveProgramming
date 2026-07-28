#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> arr(2*n, vector<int>(2*n));
    for(int i=0; i<2*n; i++){
        for(int j=0; j<2*n; j++){
            if(i == 0 && j == 0){
                arr[i][j] = 1;
                continue;
            }
            if(j == 0){
                int val = arr[i-1][j];
                if(i%2 == 0){
                    val = (1-val);
                }
                arr[i][j] = val;
                continue;
            }
            int val = arr[i][j-1];
            if(j%2 == 0){
                val = (1-val);
            }
            arr[i][j] = val;
        }
    }
    for(int i=0; i<2*n; i++){
        for(int j=0; j<2*n; j++){
            if(arr[i][j] == 1){
                cout << "#";
            } else{
                cout << ".";
            }
        }
        cout << endl;
    }
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