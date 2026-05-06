#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll total = 0;
        for(int i=0; i<n; i++) total += arr[i];
        if(total > x+y){
            cout << "NO" << endl;
            continue;
        }
        vector<ll> a(n, 0);
        vector<ll> b(n, 0);
        int flag = 1;
        int allone = 1;
        int allzero = 1;
        for(int i=0; i<n; i++){
            ll req = arr[i]/2 + 1;
            if(s[i] == '0'){
                allone = 0;
                if(x < req){
                    flag = 0;
                    break;
                }
                x -= req;
                a[i] += req;
            } else{
                allzero = 0;
                if(y < req){
                    flag = 0;
                    break;
                }
                y -= req;
                b[i] += req;
            }
        }
        if(!flag){
            cout << "NO" << endl;
            continue;
        }
        if((!allone) && (!allzero)){
            cout << "YES" << endl;
            continue;
        }
        if(allone){
            for(int i=0; i<n; i++){
                ll val = b[i]-1;
                x = max((ll)0, x-val);
            }
            if(x > y){
                cout << "NO" << endl;
            } else{
                cout << "YES" << endl;
            }
        } else{
            for(int i=0; i<n; i++){
                ll val = a[i]-1;
                y = max((ll)0, y-val);
            }
            if(y > x){
                cout << "NO" << endl;
            } else{
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}