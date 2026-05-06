#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        ll k;
        cin >> n >> m >> k;
        map<ll,ll> a;
        for(int i=0; i<m; i++){
            ll val;
            cin >> val;
            a[val]++;
        }
        vector<ll> x(n), y(n), z(n);
        for(int i=0; i<n; i++){
            cin >> x[i] >> y[i] >> z[i];
        }
        vector<pair<ll,ll>> arr(n);
        for(int i=0; i<n; i++){
            k -= y[i];
            arr[i].first = z[i] - y[i];
            arr[i].second = x[i];
        }
        sort(arr.begin(), arr.end());
        vector<ll> temp;
        ll ans = 0;
        for(int i=n-1; i>=0; i--){
            auto it = a.lower_bound(arr[i].second);
            if(it != a.end()){
                ans++;
                ll beauty = it->first;
                a[beauty]--;
                if(a[beauty] == 0) a.erase(beauty);
            } else{
                temp.push_back(arr[i].first);
            }
        }
        reverse(temp.begin(), temp.end());
        ll i = 0;
        for(; i<temp.size(); i++){
            if(temp[i] > k) break;
            k -= temp[i];
        }
        ans += i;
        cout << ans << endl;
    }
    return 0;
}