#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> st;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            st.insert(x);
        }
        vector<int> ans(n+1, 1e9);
        for(auto it : st){
            ans[it] = 1;
        }
        for(int i=1; i<=n; i++){
            if(ans[i] == 1e9) continue;
            for(auto it : st){
                ll j = (ll)i * (ll)it;
                if(j > n) break;
                ans[j] = min(ans[j], ans[i]+1);
            }
        }
        for(int i=1; i<=n; i++){
            if(ans[i] == 1e9) cout << -1 << " ";
            else cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}