#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(n);
        a[0] = 1;
        for(int i=1; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i < n && j < n){
            if(a[i] >= b[j]){
                ans++;
                j++;
            } else{
                i++;
                j++;
            }
        }
        cout << ans << endl;
    }
}