#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll c;
        cin >> n >> c;
        vector<ll> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            arr[i] += (ll)(i + 1);
        }
        sort(arr.begin(), arr.end());
        int cnt = 0;
        ll sum = 0;
        for(int i=0; i<n; i++){
            if(sum + arr[i] > c) break;
            sum += arr[i];
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}