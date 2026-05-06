#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<vector<int>> matrix(n, vector<int>(n));
        vector<vector<int>> rotated(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> matrix[i][j];
                rotated[i][j] = matrix[i][j];
            }
        }
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n; j++){
                swap(rotated[i][j], rotated[n-i-1][j]);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                swap(rotated[i][j], rotated[i][n-j-1]);
            }
        }
        int total = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(rotated[i][j] != matrix[i][j]) total++;
            }
        }
        total /= 2;
        if(k >= total){
            if(n&1 || k % 2 == total % 2){
                cout << "YES" << endl;
                continue;
            }  
        } 
        cout << "NO" << endl;

    }
    return 0;
}