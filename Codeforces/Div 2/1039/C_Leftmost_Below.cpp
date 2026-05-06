#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> preMin(n);
        preMin[0] = INT_MAX;
        for(int i=1; i<n; i++){
            preMin[i] = min(preMin[i-1], arr[i-1]);
        }
        int flag = 1;
        for(int i=1; i<n; i++){
            ll val = (ll)preMin[i] + (ll)(preMin[i]-1);
            if(arr[i] > val) flag = 0;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}