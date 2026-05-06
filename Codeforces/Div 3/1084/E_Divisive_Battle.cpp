#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    vector<ll> p(1e6+1, -1);
    p[1] = 1;
    for(ll i=2; i<=1e6; i++){
        if(p[i] == -1){
            for(ll j=i; j<=1e6; j*=i){
                p[j] = i;
            }
        }
    }
    vector<ll> isprime(1e6+10, 1);
    for(ll i=2; i*i<=1e6; i++){
        if(isprime[i]){
            for(ll j=i*i; j<=1e6; j+=i){
                isprime[j] = 0;
            }
        }
    }
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        if(is_sorted(arr.begin(), arr.end())){
            cout << "Bob" << endl;
            continue;
        }
        int prev = -1;
        int flag = 0;
        for(int i=0; i<n; i++){
            int cur;
            if(isprime[p[arr[i]]]){
                cur = p[arr[i]];
            } else{
                flag = 1;
                break;
            }
            if(prev > cur){
                flag = 1;
                break;
            }
            prev = cur;
        }
        if(flag) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    return 0;
}