#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, n;
        cin >> a >> b >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            b += min(arr[i], a-1);
        }
        cout << b << endl;
    }
    return 0;
}