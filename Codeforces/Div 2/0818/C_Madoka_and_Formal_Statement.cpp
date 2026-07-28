#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++){
        if(a[i] > b[i]){
            cout << "NO" << endl;
            return;
        }
    }
    int minInd = 0;
    for(int i=0; i<n; i++){
        if(b[i] < b[minInd]) minInd = i;
    }
    for(int i=0; i<n; i++){
        a[i] = max(a[i], b[minInd]);
    }
    int i = (minInd - 1 + n) % n;
    while(i != minInd){
        if(a[i] == b[i]){
            i = (i-1+n) % n;
            continue;
        }
        int next = a[(i+1)%n];
        if(b[i] > next+1){
            cout << "NO" << endl;
            return;
        } 
        a[i] = b[i];
        i = (i-1+n) % n;
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