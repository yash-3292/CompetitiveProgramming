#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll sum = 0;
        queue<pair<ll,int>> q;
        q.push({sum,1});
        ll ans = 0;
        for(int i=0; i<n; i++){
            sum += (ll)arr[i];
            ll thres = sum - (ll)x;
            int cnt = 0;
            while(!q.empty() && q.front().first < thres){
                cnt += q.front().second;
                q.pop();
            }
            ans += (ll)cnt;
            cnt++;
            q.push({sum, cnt});
        }
        ans = (ll)(n)*(ll)(n+1) / (ll)2 - ans;
        cout << ans << endl;
    }
}