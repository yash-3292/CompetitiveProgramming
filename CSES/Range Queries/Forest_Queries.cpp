#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char x;
            cin >> x;
            if(x == '*') arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i > 0) arr[i][j] += arr[i-1][j];
            if(j > 0) arr[i][j] += arr[i][j-1];
            if(i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
        }
    }
    while(q--){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;
        int ans = arr[y2][x2];
        if(y1 > 0) ans -= arr[y1-1][x2];
        if(x1 > 0) ans -= arr[y2][x1-1];
        if(x1 > 0 && y1 > 0) ans += arr[y1-1][x1-1];
        cout << ans << endl;
    }
    cout << endl;
    return 0;
}