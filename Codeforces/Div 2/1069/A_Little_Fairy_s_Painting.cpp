#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int,int> mpp;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            mpp[x] = 1;
        }
        int val = mpp.size();
        int ans;
        for(auto it : mpp){
            if(it.first >= val){
                ans = it.first;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}