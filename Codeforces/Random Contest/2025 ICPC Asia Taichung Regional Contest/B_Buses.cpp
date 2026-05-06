#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){
    fastIO();
    int n, m, l, x, y;
    cin >> n >> m >> l >> x >> y;
    map<int, db> mpp;
    for(int i=0; i<n; i++){
        int s, t;
        cin >> s >> t;
        db time = (db)(t-s)/(db)x + (db)(l-t)/(db)y;
        // cout << time << " ";
        if(mpp.find(s) == mpp.end()){
            mpp[s] = time;
        } else{
            mpp[s] = min(mpp[s], time);
        }
    }
    vector<int> larr;
    vector<db> tarr;
    for(auto it : mpp){
        larr.push_back(it.first);
        tarr.push_back(it.second);
    }
    int sz = tarr.size();
    for(int i=1; i<sz; i++){
        tarr[i] = min(tarr[i], tarr[i-1]);
    }
    // for(int i=0; i<sz; i++){
    //     cout << larr[i] << " " << tarr[i] << endl;
    // }
    for(int i=0; i<m; i++){
        int p;
        cin >> p;
        int pos = upper_bound(larr.begin(), larr.end(), p) - larr.begin();
        db ans = (db)(l-p)/(db)y;
        if(pos != 0){
            ans = min(tarr[pos-1], ans);
        }
        cout << fixed << setprecision(6) << ans << "\n";
    }
    return 0;
}