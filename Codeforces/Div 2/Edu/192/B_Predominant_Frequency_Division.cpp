#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int cnt = 0;
    int num = 0;
    int i = 0;
    while(i < n){
        if(arr[i] > 1) cnt++;
        num++;
        if(cnt <= num/2) break;
        i++;
    }
    i++;
    if(i >= n){
        cout << "NO" << endl;
        return;
    }
    if(i < n && (i&1) && arr[i] == 3){
        i++;
    }
    cnt = 0;
    num = 0;
    while(i < n){
        if(arr[i] > 2) cnt++;
        num++;
        if(cnt <= num/2) break;
        i++;
    }
    i++;
    if(i >= n){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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