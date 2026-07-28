#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    map<int,int> mpp;
    vector<int> vis1(n+1, 0), vis2(n+1, 0);
    for(int i=1; i<=n; i++){
        if(b[i] != -1){
            int ind = i;
            int x = a[i];
            int y = b[i];
            ind = a[ind];
            x = a[x];
            y = a[y];
            while(b[ind] == -1){
                b[ind] = y;
                ind = a[ind];
                x = a[x];
                y = a[y];
            }
            if(b[ind] != y){
                cout << "NO" << endl;
                return;
            }
        }
    }
    for(auto it : b) cout << it << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}