#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        vector<int> maxi(n);
        vector<ll> sum(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        maxi[0] = arr[0];
        sum[0] = (ll)arr[0];
        for(int i=1; i<n; i++){
            maxi[i] = max(maxi[i-1], arr[i]);
            sum[i] = sum[i-1] + (ll)arr[i];
        }
        while(q--){
            int k;
            cin >> k;
            int index = upper_bound(maxi.begin(), maxi.end(), k) - maxi.begin() - 1;
            if(index < 0) cout << 0 << " ";
            else cout << sum[index] << " ";
        }
        cout << endl;
    }
    return 0;
}