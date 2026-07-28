#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a(n), b(n, 1e15), c(n);
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n; i++) cin >> c[i];
    for(ll i=1; i<n; i++){
        if(c[i-1] > c[i]){
            cout << "No" << endl;
            return;
        }
    }
    b[0] = c[0];
    for(ll i=1; i<n; i++){
        if(c[i-1] < c[i]){
            b[i] = c[i];
        }
    }
    for(ll i=0; i<n; i++){
        if(s[i] == '1'){
            if(i == 0){
                if(b[0] != a[0]){
                    cout << "No" << endl;
                    return;
                }
            } else{
                if(b[i-1] != 1e15 && b[i] != 1e15){
                    if(b[i-1] + a[i] != b[i]){
                        cout << "No" << endl;
                        return;
                    }
                } else if(b[i-1] != 1e15){
                    b[i] = b[i-1] + a[i];
                } else if(b[i] != 1e15){
                    b[i-1] = b[i] - a[i];
                }
            }
        }
    }
    for(ll i=n-1; i>=0; i--){
        if(s[i] == '1'){
            if(i == 0){
                if(b[0] != a[0]){
                    cout << "No" << endl;
                    return;
                }
            } else{
                if(b[i-1] != 1e15 && b[i] != 1e15){
                    if(b[i-1] + a[i] != b[i]){
                        cout << "No" << endl;
                        return;
                    }
                } else if(b[i-1] != 1e15){
                    b[i] = b[i-1] + a[i];
                } else if(b[i] != 1e15){
                    b[i-1] = b[i] - a[i];
                }
            }
        }
    }
    ll maxi = b[0];
    for(ll i=1; i<n; i++){
        if(b[i] != 1e15){
            maxi = max(maxi, b[i]);
        }
        if(maxi > c[i]){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    a[0] = b[0];
    ll sum = b[0];
    for(int i=1; i<n; i++){
        if(b[i] == 1e15){
            if(b[i-1] != 1e15){
                a[i] = -1e16;
                sum += a[i];
            } else{
                if(s[i] == '1'){
                    sum += a[i];
                } else{
                    sum += 0;
                }
            }
        } else{
            if(s[i] == '1'){
                sum += a[i];
            } else{
                a[i] = b[i] - sum;
                sum = b[i];
            }
        }
    }
    for(int i=0; i<n; i++) cout << a[i] << " ";
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