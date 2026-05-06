#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; 
        vector<ll> p(n);
        vector<ll> s(n);
        for(int i=0; i<n; i++) cin >> p[i];
        for(int i=0; i<n; i++) cin >> s[i];
        vector<ll> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = p[i]*s[i]/__gcd(p[i], s[i]);
        }
        int flag = 1;
        ll val = 0;
        for(int i=0; i<n; i++){
            val = __gcd(val, arr[i]);
            if(val != p[i]){
                flag = 0;
                break;
            }
        }
        val = 0;
        for(int i=n-1; i>=0; i--){
            val = __gcd(val, arr[i]);
            if(val != s[i]){
                flag = 0;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
    return 0;
}