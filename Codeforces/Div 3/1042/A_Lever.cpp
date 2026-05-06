#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        int ans = 0;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        for(int i=0; i<n; i++){
            if(a[i] > b[i]){
                ans += a[i]-b[i];
            }
        }
        ans++;
        cout << ans << endl;
    }
    return 0;
}