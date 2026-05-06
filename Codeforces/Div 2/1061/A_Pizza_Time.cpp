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
        if(n&1){
            ans = n/2;
        } else{
            ans = n/2-1;
        }
        cout << ans << endl;
    }
    return 0;
}