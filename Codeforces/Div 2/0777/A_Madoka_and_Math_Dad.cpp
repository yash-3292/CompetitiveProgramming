#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    if(n%3 == 0 || n%3 == 2){
        for(int i=0; n > 0; i++){
            int d;
            if(i%2 == 0) d = 2;
            else d = 1;
            n -= d;
            cout << d;
        }
    } else if(n%3 == 1){
        for(int i=0; n > 0; i++){
            int d;
            if(i%2 == 0) d = 1;
            else d = 2;
            n -= d;
            cout << d;
        }
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