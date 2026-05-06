#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    vector<int> cnta;
    vector<int> cntb;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i] == 1){
            cnt++;
        } else{
            if(cnt){
                cnta.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if(cnt){
        cnta.push_back(cnt);
        cnt = 0;
    }
    for(int i=0; i<m; i++){
        if(b[i] == 1){
            cnt++;
        } else{
            if(cnt){
                cntb.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if(cnt){
        cntb.push_back(cnt);
        cnt = 0;
    }
    sort(cnta.begin(), cnta.end());
    sort(cntb.begin(), cntb.end());
    n = cnta.size();
    m = cntb.size();
    if(n == 0 || m == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<int> prex(n);
    vector<int> prey(m);
    prex[0] = cnta[0];
    for(int i=1; i<n; i++) prex[i] = prex[i-1] + cnta[i];
    prey[0] = cntb[0];
    for(int i=1; i<m; i++) prey[i] = prey[i-1] + cntb[i];

    ll ans = 0;
    for(int x=1; x*x<=k; x++){
        if(k%x == 0){
            int y = k/x;

            int i = lower_bound(cnta.begin(), cnta.end(), x) - cnta.begin();
            ll val1 = (ll)prex[n-1];
            if(i != 0) val1 -= (ll)prex[i-1];
            val1 -= (ll)(n-i)*(ll)(x-1);

            int j = lower_bound(cntb.begin(), cntb.end(), y) - cntb.begin();
            ll val2 = (ll)prey[m-1];
            if(j != 0) val2 -= (ll)prey[j-1];
            val2 -= (ll)(m-j)*(ll)(y-1);
            
            ans += val1 * val2;
        }
    }

    for(int y=1; y*y<=k; y++){
        if(k%y == 0){
            int x = k/y;
            
            if(x == y) continue;

            int i = lower_bound(cnta.begin(), cnta.end(), x) - cnta.begin();
            ll val1 = (ll)prex[n-1];
            if(i != 0) val1 -= (ll)prex[i-1];
            val1 -= (ll)(n-i)*(ll)(x-1);

            int j = lower_bound(cntb.begin(), cntb.end(), y) - cntb.begin();
            ll val2 = (ll)prey[m-1];
            if(j != 0) val2 -= (ll)prey[j-1];
            val2 -= (ll)(m-j)*(ll)(y-1);
            
            ans += val1 * val2;
        }
    }

    cout << ans << endl;
    return 0;
}