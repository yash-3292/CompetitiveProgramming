#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> arr(n);
        map<pair<int,int>,int> mpp;
        ll cnt = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            int r1 = arr[i] % x;
            int r2 = arr[i] % y;
            cnt += (ll)mpp[make_pair((x-r1)%x, r2)];
            mpp[make_pair(r1, r2)]++;
        } 
        cout << cnt << endl;
    }
    return 0;
}