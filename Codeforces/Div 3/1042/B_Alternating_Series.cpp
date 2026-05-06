#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n&1){
            for(int i=1; i<=n; i++){
                if(i&1) cout << -1 << " ";
                else cout << 3 << " ";
            }
        } else{
            for(int i=1; i<n; i++){
                if(i&1) cout << -1 << " ";
                else cout << 3 << " ";
            }
            cout << 2 << " ";
        }
        cout << endl;
    }
    return 0;
}