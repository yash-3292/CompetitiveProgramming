#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int flag = 1;
        ll gcd = -1;
        for(int i=0; i<n; i+=2){
            if(gcd == -1) gcd = arr[i];
            else gcd = __gcd(gcd, arr[i]);
        }
        for(int i=1; i<n; i+=2){
            if(arr[i] % gcd == 0){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << gcd << endl;
            continue;
        }
        flag = 1;
        gcd = -1;
        for(int i=1; i<n; i+=2){
            if(gcd == -1) gcd = arr[i];
            else gcd = __gcd(gcd, arr[i]);
        }
        for(int i=0; i<n; i+=2){
            if(arr[i] % gcd == 0){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << gcd << endl;
            continue;
        }
        cout << 0 << endl;
    }
    return 0;
}