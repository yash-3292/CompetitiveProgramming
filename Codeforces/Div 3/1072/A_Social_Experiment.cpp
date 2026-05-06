#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans;
        if(n == 2 || n == 3) ans = n;
        else if(n&1) ans = 1;
        else ans = 0;
        cout << ans << endl;
    }
    return 0;
}