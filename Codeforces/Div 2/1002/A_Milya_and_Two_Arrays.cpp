#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    map<int,int> freq1, freq2;
    for(int i=0; i<n; i++){
        freq1[a[i]]++;
        freq2[b[i]]++;
    }
    if(freq1.size() == 1 && freq2.size() == 1){
        cout << "NO" << endl;
        return;
    }
    if(freq1.size() == 1 && freq2.size() == 2){
        cout << "NO" << endl;
        return;
    }
    if(freq1.size() == 2 && freq2.size() == 1){
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