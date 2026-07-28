#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> a1, a2;
    int val1 = arr[(n/2) - 1];
    int val2 = arr[(n/2)];
    for(int i=n/2-1; i>=0; i--){
        a1.push_back(val1 - arr[i]);
    }
    for(int i=n/2; i<n; i++){
        a2.push_back(arr[i] - val2);
    }
    if(a1 == a2) cout << "Yes" << endl;
    else cout << "No" << endl;
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