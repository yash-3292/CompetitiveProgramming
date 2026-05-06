#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    int minr = n-1;
    int minc = m-1;
    int maxr = 0;
    int maxc = 0;
    vector<vector<char>> arr(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '*'){
                minr = min(minr, i);
                minc = min(minc, j);
                maxr = max(maxr, i);
                maxc = max(maxc, j);
            }
        }
    }
    for(int i=minr; i<=maxr; i++){
        for(int j=minc; j<=maxc; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}