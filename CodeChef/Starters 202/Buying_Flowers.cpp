#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        if(n&1){
            n -= 3;
            ans += 5;
        }
        ans += (n/6)*10;
        n = n%6;
        ans += (n/2)*4;
        cout << ans << endl;
    }
    return 0;
}