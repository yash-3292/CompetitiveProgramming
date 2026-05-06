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
        for(int i=0; i*2<=n; i++){
            int val = n - 2*i;
            if(val%4 == 0){
                ans++;
            }
        }
        cout << ans << endl;
    }
}