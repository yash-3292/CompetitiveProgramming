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
        for(int i=0; i<n; i++){
            cin >> arr[i].first;
            arr[i].second = i+1;
        }
        sort(arr.begin(), arr.end());
        ll cnt = 0;
        for(int i=0; i<n; i++){
            ll val = arr[i].first;
            int x = arr[i].second;
            for(int j=i+1; j<n; j++){
                if(val * (ll)arr[j].first > (ll)(2 * n)) break;
                int y = arr[j].second;
                if(x + y == (int)val * arr[j].first) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}