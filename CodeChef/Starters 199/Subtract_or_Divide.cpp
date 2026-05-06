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
            ans = (n+1)/2;
        } else{
            ans += n/2;
            int val = n/2;
            if(val%2 == 0) val--;
            ans += (val+1)/2;
        }
        cout << ans << endl;
    }
    return 0;
}