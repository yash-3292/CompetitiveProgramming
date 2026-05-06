#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        int d = abs(count(a.begin(), a.end(), 0) - count(b.begin(), b.end(), 0));
        int ans = d;
        for(int i=0; i<n; i++){
            if(a[i] != b[i]){
                if(d) d--;
                else{
                    ans++;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}