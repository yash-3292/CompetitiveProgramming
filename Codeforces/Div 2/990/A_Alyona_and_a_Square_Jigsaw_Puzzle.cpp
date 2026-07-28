#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int sum = 0;
    int ans= 0 ;
    for(int i=0; i<n; i++){
        sum += arr[i];
        int flag = 0;
        for(int j=1; j*j<=sum; j+=2){
            if(j*j == sum){
                flag = 1;
                break;
            }
        }
        if(flag) ans++;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}