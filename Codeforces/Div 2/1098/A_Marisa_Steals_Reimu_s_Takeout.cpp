#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int z = 0;
    int o = 0;
    int t = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0) z++;
        else if(arr[i] == 1) o++;
        else t++;
    }
    int m = min(o, t);
    int ans = z + m;
    o -= m;
    t -= m;
    ans += o/3;
    ans += t/3;
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}