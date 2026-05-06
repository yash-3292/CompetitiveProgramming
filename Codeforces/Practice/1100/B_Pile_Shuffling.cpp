#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll ans = 0;
        for(int i=0; i<n; i++){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if(a > c){
                ans += (ll)(a-c);
                if(b > d){
                    ans += (ll)c;
                    ans += (ll)(b-d);
                } 
            } else{
                if(b > d){
                    ans += (ll)a;
                    ans += (ll)(b-d);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}