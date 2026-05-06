#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    int mini = 1e9;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            ans += (ll)x;
            if(i+j == n-1) mini = min(mini, x);
        }
    }
    ans -= (ll)mini;
    cout << ans << endl;
    return 0;
}