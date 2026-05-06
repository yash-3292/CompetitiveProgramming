#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int give1 = 0;
        while(give1 < k){
            give1 += n;
        }
        int give2 = 0;
        while(give2 < k){
            give2 += m;
        }
        int give = min(give1, give2);
        int ans = n*m - give;
        cout << ans << endl;
    }
    return 0;
}