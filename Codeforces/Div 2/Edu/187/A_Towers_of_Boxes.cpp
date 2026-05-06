#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, d;
        cin >> n >> m >> d;
        int len = d/m + 1;
        int ans = n/len + (n%len != 0);
        cout << ans << endl;
    }
    return 0;
}