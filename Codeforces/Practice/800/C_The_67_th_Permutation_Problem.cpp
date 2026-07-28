#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=n+1; i<=3*n; i++){
        arr.push_back(i);
    }
    for(int i=1; i<=n; i++){
        cout << i << " ";
        cout << arr.back() << " ";
        arr.pop_back();
        cout << arr.back() << " ";
        arr.pop_back();
    }
    cout << endl;
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