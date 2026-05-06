#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x, y;
        cin >> n >> x >> y;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll val = x;
        for(int i=0; i<n; i++){
            val ^= (ll)(arr[i]);
        }
        if(val%2 == y%2){
            cout << "Alice" << endl;
        } else{
            cout << "Bob" << endl;
        }
    }
    return 0;
}