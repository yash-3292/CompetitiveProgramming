#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int l = n-1;
    int r = n-1;
    int time = 0;
    int ans = 0;
    while(l >= 0){
        time += arr[l];
        while(time > t){
            time -= arr[r];
            r--;
        }
        ans = max(ans, r-l+1);
        l--;
    }
    cout << ans << endl;
    return 0;
}