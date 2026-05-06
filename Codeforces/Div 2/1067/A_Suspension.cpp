#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int y, r;
        cin >> y >> r;
        int ans = r + y/2;
        ans = min(ans, n);
        cout << ans << endl;
    }
    return 0;
}