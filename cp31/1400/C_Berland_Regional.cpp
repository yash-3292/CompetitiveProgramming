#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> u(n);
        vector<int> s(n);
        map<int,vector<int>> mpp;
        vector<ll> ans(n+1,0);
        for(int i=0; i<n; i++) cin >> u[i];
        for(int i=0; i<n; i++){
            cin >> s[i];
            mpp[u[i]].push_back(s[i]);
        }
        for(auto it : mpp){
            vector<int> arr(it.second);
            sort(arr.begin(), arr.end());
            int size = arr.size();
            vector<ll> presum(size);
            presum[0] = (ll)arr[0];
            for(int i=1; i<size; i++) presum[i] = presum[i-1] + (ll)arr[i];
            for(int i=1; i<=size; i++){
                int num = size%i;
                ll val = presum[size-1];
                if(num != 0){
                    val -= presum[num-1];
                }
                ans[i] += val;
            }
        }
        for(int i=1; i<=n; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}