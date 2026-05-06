#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        map<int,int> freq;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
                freq[arr[i][j]]++;
            }
        }
        int maxi = 0;
        for(auto it : freq){
            maxi = max(maxi, it.second);
        }
        if(maxi+n <= n*n){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}