#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> arr(n);
        vector<int> l(n);
        vector<int> r(n);
        for(int i=0; i<n; i++){
            cin >> l[i] >> r[i];
            arr[i].first = l[i];
            arr[i].second = r[i];
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        int ans = n; 
        for(int i=0; i<n; i++){
            int val = 0;
            val += lower_bound(r.begin(), r.end(), arr[i].first) - r.begin();
            val += n - (upper_bound(l.begin(), l.end(), arr[i].second) - l.begin());
            ans = min(ans, val);
        }
        cout << ans << endl;
    }
    return 0;
}