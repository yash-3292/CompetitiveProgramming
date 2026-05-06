#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n /= 2;
        int ans = n * (n+1);
        cout << ans << endl;
    }
    return 0;
}