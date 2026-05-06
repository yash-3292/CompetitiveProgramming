#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class SparseTable {
private:
    vector<vector<ll>> st;
    vector<ll> log2_values;
    ll n, max_log;
public:
    SparseTable(const vector<ll> & input){
        n = input.size();
        max_log = log2(n) + 1;
        st.assign(n, vector<ll>(max_log, 1e18));
        log2_values.assign(n+1, 0);

        for(int i=2; i<=n; i++){
            log2_values[i] = log2_values[i/2] + 1;
        }

        for(int i=0; i<n; i++){
            st[i][0] = input[i];
        }

        for(int k=1; k<max_log; k++){
            for(int i=0; i+(1<<k)<=n; i++){
                st[i][k] = min(st[i][k-1], st[i+(1LL<<(k-1))][k-1]);
            }
        }
    }

    ll query(int l, int r){
        int len = r-l+1;
        int k = log2_values[len];
        return min(st[l][k], st[r-(1LL<<k)+1][k]);
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> arr(m);
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        arr[i] = n - x - 1;
    }
    SparseTable st(arr);
    int q;
    cin >> q;
    while(q--){
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        x1--; y1--; x2--; y2--;
        x1 = n - x1 - 1;
        x2 = n - x2 - 1;
        if((abs(x1-x2)%k != 0) || (abs(y1-y2)%k != 0)){
            cout << "NO" << endl;
            continue;
        }
        int x = min(x1, x2);
        x = (x%k);
        if(y1 > y2) swap(y1, y2);
        int val = st.query(y1, y2);
        if(val >= x){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}