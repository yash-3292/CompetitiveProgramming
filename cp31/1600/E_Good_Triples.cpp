#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int temp = n;
        ll ans = 1;
        while(temp > 0){
            int digit = temp%10;
            ans *= ((ll)(digit+2)*(ll)(digit+1))/2;
            temp /= 10;
        }
        cout << ans << endl;
    }
    return 0;
}