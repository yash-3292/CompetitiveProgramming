#include<bits/stdc++.h>
using namespace std;

void fill(vector<vector<int>> &arr, int n){
    int cnt = n*n - 1;
    if(n%2 == 0){
        int k;
        if(arr.size() % 2 == 0){
            k = (arr.size()- n)/2;
        } else{
            k = (arr.size()- n+1)/2;
        }
        for(int i=n-1; i>=0; i--){
            arr[i+k][n-1+k] = cnt;
            cnt--;
        }
        for(int j=n-2; j>=0; j--){
            arr[n-1+k][j+k] = cnt;
            cnt--;
        }
    }
    else{
        int k;
        if(arr.size() % 2 != 0){
            k = (arr.size()- n)/2;
        } else{
            k = (arr.size()- n-1)/2;
        }
        arr[k][k] = cnt;
        if(n == 1) return;
        cnt--;
        for(int j=n-1; j>0; j--){
            arr[k][j+k] = cnt;
            cnt--;
        }
        for(int i=n-1; i>0; i--){
            arr[i+k][k] = cnt;
            cnt--;
        }
    }
    fill(arr,n-1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        fill(arr, n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}