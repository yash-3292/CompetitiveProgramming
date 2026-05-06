#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int val = min(a, b/2);
        int ans = val*3;
        cout << ans << endl;
    }
    return 0;
}