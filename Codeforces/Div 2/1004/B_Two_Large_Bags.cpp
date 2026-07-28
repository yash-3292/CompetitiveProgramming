#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> freq(n+10, 0);
    for(int i=0; i<n; i++) freq[arr[i]]++;
    for(int i=1; i<=n+1; i++){
        // cout << i << " " << freq[i] << endl;
        if(freq[i]%2 == 0){
            if(freq[i] >= 2) freq[i+1] += freq[i] - 2;
            continue;
        }
        if(freq[i] == 1){
            cout << "No" << endl;
            return;
        }
        freq[i]--;
        freq[i+1]++;
        if(freq[i] >= 2) freq[i+1] += freq[i] - 2;
    }
    cout << "Yes" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}