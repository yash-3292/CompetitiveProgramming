#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        if(n == 1){
            cout << arr[0] << endl;
            continue;
        }
        ll sum = 0;
        ll maxi1 = INT_MIN;
        ll mini1 = INT_MAX;
        ll maxi2 = INT_MIN;
        ll mini2 = INT_MAX;
        for(int i=0; i<n; i++){
            if(i&1){
                sum -= (ll)arr[i];
                maxi1 = max((ll)(arr[i]+i), maxi1);
                maxi2 = max((ll)(arr[i]-i), maxi2);
            } else{
                sum += (ll)arr[i];
                mini1 = min((ll)(arr[i]+i), mini1);
                mini2 = min((ll)(arr[i]-i), mini2);
            }
        } 
        vector<int> temp(n);
        sort(temp.begin(), temp.end());
        if(temp[0] == temp[n-1]){
            ll ans = sum + n-1;
            cout << ans << " ";
            cout << endl;   
        }
        ll val = max(maxi1-mini1, maxi2-mini2);
        val = max(val, (ll)0);
        sum += val;
        cout << sum << endl;
    }
    return 0;
}