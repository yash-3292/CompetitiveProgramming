#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    int ind = -1;
    for(int i=21; i>=0; i--){
        int x = 0;
        int y = 0;
        for(int j=0; j<n; j++){
            if(a[j]&(1<<i)) x++;
            if(b[j]&(1<<i)) y++;
        }
        if((x%2) != (y%2)){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        cout << "Tie" << endl;
        return;
    }
    for(int i=n-1; i>=0; i--){
        int x = 0;
        int y = 0;
        if(a[i]&(1<<ind)) x = 1;
        if(b[i]&(1<<ind)) y = 1;
        if((x%2) != (y%2)){
            if(i%2 == 0){
                cout << "Ajisai" << endl;
            } else{
                cout << "Mai" << endl;
            }
            return;
        } 
    }
    cout << "not possible" << endl;
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