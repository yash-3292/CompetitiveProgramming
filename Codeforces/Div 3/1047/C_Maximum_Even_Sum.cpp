#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll ans;
        if((a&1) && (b&1)){
            ans = a*b + 1;
        } else if(a&1){
            if(b%4 == 0){
                ans = a*(b/2)+2;
            } else{
                ans = -1;
            }
        } else if(b&1){
            ans = -1;
        } else{
            ans = a*(b/2) + 2;
        }
        cout << ans << endl;
    }
    return 0;
}