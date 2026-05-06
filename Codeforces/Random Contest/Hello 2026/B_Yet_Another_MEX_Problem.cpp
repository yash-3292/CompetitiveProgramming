#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        map<int,int> mpp;
        int mex = 0;
        for(int i=0; i<n; i++){
            int x; 
            cin >> x;
            mpp[x] = 1;
        }
        while(mpp.find(mex) != mpp.end()){
            mex++;
        }
        int ans = min(k-1, mex);
        cout << ans << endl;
    }
    return 0;
}