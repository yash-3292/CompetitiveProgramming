#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, p;
        cin >> n >> p;
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i].second;
        }
        for(int i=0; i<n; i++){
            cin >> arr[i].first;
        }
        sort(arr.begin(), arr.end());
        ll ans = (ll)p;
        int total = n-1;
        for(auto it : arr){
            int b = it.first;
            int a = it.second;
            if(b < p){
                if(total > a){
                    ans += (ll)b * (ll)a;
                    total -= a;
                } else{
                    ans += (ll)b * (ll)total;
                    total = 0;
                }
            }
        }
        ans += (ll)total * (ll)p;
        cout << ans << endl;
    }
    return 0;
}