#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

ll calc(int p, int q, int side){
    ll val = (ll)side * (ll)q;
    val = val / (ll)p;
    return val;
}

int f(int p, int a, int b, int c, int k){
    int l = 1;
    int r = 1e9;
    int ans = -1;
    while(l <= r){
        int mid = l + (r-l)/2;
        ll val1 = calc(p, mid, a);
        ll val2 = calc(p, mid, b);
        ll val3 = calc(p, mid, c);
        if(val1 > 1e9 || val2 > 1e9 || val3 > 1e9 || val1*val2 > 1e9 || val2*val3 > 1e9 || val1*val3 > 1e9){
            if(val1 != 0 && val2 != 0 && val3 != 0) ans = mid; 
            r = mid-1;
            continue;
        }
        ll val = val1*val2*val3;
        // cout  << mid << " " << val << "  ";
        if(val >= k){
            ans = mid;
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    // cout << endl;
    // cout << p << " " << ans << endl;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        int k;
        cin >> a >> b >> c;
        cin >> k;
        pair<int,int> p, p1, p2, p3;
        p.first = 1;
        p.second = f(1, a, b, c, k);
        p1.first = a;
        p1.second = f(a, a, b, c, k);
        p2.first = b;
        p2.second = f(b, a, b, c, k);
        p3.first = c;
        p3.second = f(c, a, b, c, k);
        if(p1.second != -1 && (db)p.first/(db)p.second < (db)p1.first/(db)p1.second){
            p.first = p1.first;
            p.second = p1.second;
        }
        if(p2.second != -1 && (db)p.first/(db)p.second < (db)p2.first/(db)p2.second){
            p.first = p2.first;
            p.second = p2.second;
        }
        if(p3.second != -1 && (db)p.first/(db)p.second < (db)p3.first/(db)p3.second){
            p.first = p3.first;
            p.second = p3.second;
        }
        int gcd = __gcd(p.first, p.second);
        p.first = p.first/gcd;
        p.second = p.second/gcd;
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}