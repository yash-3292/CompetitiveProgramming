#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        vector<int> sufMax(n);
        sufMax[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            sufMax[i] = max(sufMax[i+1], a[i+1]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(x >= b[i]){
                if(x > sufMax[i]){
                    ans++;
                    x--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}