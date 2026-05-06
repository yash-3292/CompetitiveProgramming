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
        for(int i=n-2; i>=0; i--){
            if(arr[i+1] > 0) arr[i] += arr[i+1];
        }
        int ans = 0;
        for(int i=0; i<n; i++) if(arr[i] > 0) ans++;
        cout << ans << endl;
    }
    return 0;
}