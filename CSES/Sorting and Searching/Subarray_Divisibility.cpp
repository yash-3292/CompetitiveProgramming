#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> mpp(n, 0);
    for(int i=0; i<n; i++) cin >> arr[i];
    int sum = 0;
    ll ans = 0;
    for(int i=0; i<n; i++){
        sum += (arr[i]%n+n)%n;
        sum = sum%n;
        if(sum == 0){
            ans++;
            ans += (ll)mpp[0];
        } else{
            ans += (ll)mpp[sum];
        }
        mpp[sum]++;
    }
    cout << ans << endl;
    return 0;
}