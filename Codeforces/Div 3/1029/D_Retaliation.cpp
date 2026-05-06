#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int flag = 1;
        ll d = arr[1] - arr[0];
        for(int i=1; i<n; i++){
            if(arr[i] - arr[i-1] != d){
                flag = 0;
                break;
            }
        }
        if(!flag){
            cout << "NO" << endl;
            continue;
        }
        ll val = arr[0] - d;
        if(val % (n+1) != 0){
            cout << "NO" << endl;
            continue;
        } 
        ll y = val / (n+1);
        ll x = y + d;
        if(x < 0 || y < 0){
            cout << "NO" << endl;
            continue;
        } 
        cout << "YES" << endl;
    }
    return 0;
}