#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> b(n);
        for(int i=0; i<n; i++) cin >> b[i];
        int x = 1;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            if(i == 0){
                a[i] = x;
                x++;
                continue;
            }
            ll val = b[i] - b[i-1];
            if(i+1 == val){
                a[i] = x;
                x++;
                continue;
            }
            a[i] = a[i-(int)val];
        }
        for(auto it : a) cout << it << " ";
        cout << endl;
    }
    return 0;
}