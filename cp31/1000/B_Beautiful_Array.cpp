#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll k, b, s;
        cin >> n >> k >> b >> s;
        vector<ll> arr(n);
        ll prod = k*b;
        if(s < prod || s - prod > (ll)n * (k-1)){
            cout << -1 << endl;
            continue;
        }
        arr[0] = prod;
        ll cnt = s - prod;
        for(int i=n-1; i>=0; i--){
            if(cnt >= k-1){
                arr[i] += k-1;
                cnt -= k-1;
            } else{
                arr[i] += cnt;
                cnt = 0;
            }
            if(cnt == 0){
                break;
            }
        }
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
