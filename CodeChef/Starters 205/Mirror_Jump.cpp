#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int ans;
        if(n-k <= k-1){
            ans = n-k;
        } else{
            ans = k;
        }
        cout << ans << endl;
    }
    return 0;
}