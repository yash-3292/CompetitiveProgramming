#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for(int i=0; i<n/2; i++){
        ans += (ll)arr[n-i-1] - (ll)arr[i];
    }
    cout << ans << endl;
    return 0;
}