#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int x, y;
    cin >> x >> y;
    vector<int> freq(200, 0);
    for(int i=2; i<=x; i++){
        if(x%i == 0){
            int cnt = 0;
            while(x%i == 0){
                cnt++;
                x /= i;
            }
            freq[i] += cnt;
        }
    }
    for(int i=2; i<=y; i++){
        if(y%i == 0){
            int cnt = 0;
            while(y%i == 0){
                cnt++;
                y /= i;
            }
            freq[i] -= cnt;
            if(freq[i] < 0){
                cout << "NO" << endl;
                return;
            }
        }
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