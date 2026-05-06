#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int num = (n*n)-k;
        if(num == 1){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        vector<vector<char>> mat(n, vector<char>(n, 'R'));
        for(int j=0; j<n; j++){
            if(num == 0) break;
            if(num == n+1){
                for(int i=0; i<n-2; i++){
                    mat[i][j] = 'D';
                }
                mat[n-2][j] = 'U'; 
                num = 2;
            } else if(num >= n){
                for(int i=0; i<n-1; i++){
                    mat[i][j] = 'D';
                }
                mat[n-1][j] = 'U'; 
                num -= n;
            } else{
                for(int i=0; i<num-1; i++){
                    mat[i][j] = 'D';
                }
                mat[num-1][j] = 'U'; 
                num = 0;
            }
            if(num == 0) break;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << mat[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}