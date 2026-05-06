#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        int part = q+1;
        int x = (n%part == 0) ? n/part : n/part+1;
        int ans = x/2;
        cout << ans << endl;
    }
    return 0;
}