#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, q;
    cin >> n >> q;
    ll sum = 0;
    vector<int> arr(n);
    vector<int> flag(n, 0);
    int cnt = 0;
    int x = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += (ll)arr[i];
    }
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int i, x1;
            cin >> i >> x1;
            if(flag[i-1] == cnt){
                sum += (ll)x1 - (ll)arr[i-1];
            } else{
                sum += (ll)x1 - (ll)x;
            }
            flag[i-1] = cnt;
            arr[i-1] = x1;
        } else{
            int x1;
            cin >> x1;
            x = x1;
            sum = (ll)x * (ll)n;
            cnt++;
        }
        cout << sum << endl;
    }
    return 0;
}