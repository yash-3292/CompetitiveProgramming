#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int s, k, m;
        cin >> s >> k >> m;
        int x =  m % (2*k);
        int ans;
        if(x == 0){
            ans = s;
        } else if(x < k){
            ans = max(s-x, 0);
        } else if(x == k){
            ans = min(s, k);
        } else{
            ans = max(min(s, k) - (x-k), 0);
        }
        cout << ans << endl;
    }
    return 0;
}