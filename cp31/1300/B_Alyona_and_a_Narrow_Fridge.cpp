#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    ll h;
    cin >> n >> h;
    vector<int> arr(n);
    vector<int> sorted;
    int ans = 0;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++){
        auto pos = lower_bound(sorted.begin(), sorted.end(), arr[i]);
        sorted.insert(pos, arr[i]);
        ll sum = 0;
        for(int j=i; j>=0; j-=2){
            sum += sorted[j];
        }
        if(sum <= h) ans = i+1;
    }
    cout << ans << endl;
    return 0;
}