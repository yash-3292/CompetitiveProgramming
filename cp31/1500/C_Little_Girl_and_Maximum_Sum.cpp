#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> freq(n+1, 0);
    while(q--){
        int x, y;
        cin >> x >> y;
        x--; y--;
        freq[x]++;
        freq[y+1]--;
    }
    for(int i=1; i<n+1; i++) freq[i] = freq[i-1]+freq[i];
    sort(arr.begin(), arr.end(), greater<int>());
    sort(freq.begin(), freq.end(), greater<int>());
    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += (ll)arr[i] * (ll)freq[i];
    }
    cout << ans << endl;
    return 0;
}