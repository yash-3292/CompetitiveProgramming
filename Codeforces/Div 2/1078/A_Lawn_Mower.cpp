#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, w;
        cin >> n >> w;
        int ans = n - n/w;
        cout << ans << endl;
    }
    return 0;
}