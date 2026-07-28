#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    r--; c--;
    r = r%k;
    c = c%k;
    int diff;
    if(r < c){
        diff = abs(r-c);
    } else{
        diff = k - abs(r-c);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int mi = i%k;
            int mj = j%k;
            mi = (mi + diff) % k;
            if(mi == mj) cout << "X";
            else cout << ".";
        }
        cout << endl;
    }
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