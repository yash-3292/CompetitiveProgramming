#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, a;
    cin >> n >> a;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int l = 0, g = 0;
    for(int i=0; i<n; i++){
        if(arr[i] < a) l++;
        else if(arr[i] > a) g++;
    }
    if(l > g){
        cout << a-1 << endl;
    } else{
        cout << a+1 << endl;
    }
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