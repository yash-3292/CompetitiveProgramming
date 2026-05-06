#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, -1));
    int i = 0;
    int j = (n-1)/2;
    int cnt = 1;
    while(cnt <= n*n){
        arr[i][j] = cnt;
        if(arr[(i-1+n)%n][(j+1)%n] == -1){
            i = (i-1+n)%n;
            j = (j+1)%n;
        } else{
            i = (i+1)%n;
        }
        cnt++;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << arr[i][j] << " ";
        cout << endl; 
    }
}