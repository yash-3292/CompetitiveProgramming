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
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            ans |= x;
        }
        cout << ans << endl;
    }
    return 0;
}
