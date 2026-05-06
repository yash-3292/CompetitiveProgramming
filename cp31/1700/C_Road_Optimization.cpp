#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> d(n);
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> d[i];
    for(int i=0; i<n; i++) cin >> a[i];
    vector<vector<int>> prev(k+1, vector<int>(n, -1));
    vector<vector<int>> cur(k+1, vector<int>(n, -1));
    for(int ki=0; ki<=k; ki++){
        for(int last=0; last<n; last++){
            prev[ki][last] = (l-d[last])*a[last];
        }
    }
    for(int i=n-1; i>0; i--){
        for(int ki=0; ki<=k; ki++){
            for(int last=0; last<i; last++){
                int ans = a[last]*(d[i]-d[last]) + prev[ki][i];
                if(ki > 0){
                    int val = prev[ki-1][last];
                    ans = min(ans, val);
                }
                cur[ki][last] =  ans;
            }
        }
        prev = cur;
    }
    int ans = prev[k][0];
    cout << ans << endl;
    return 0;
}