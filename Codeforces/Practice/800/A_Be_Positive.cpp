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
        int neg = 0;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x == -1) neg++;
            else if(x == 0) ans++;
        }
        if(neg&1) ans += 2;
        cout << ans << endl;
    }
    return 0;
}