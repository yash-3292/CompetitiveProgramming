#include <bits/stdc++.h>
using namespace std;

/*
Recursive (top-down) Segment Tree — Pashka style.
Supports point set, point add, and range gcd.
0-indexed positions; gcd(l,r) inclusive.
Uses long long; identity is 0 (gcd(x,0)=|x|).
*/

typedef long long ll;

class SegmentTree {
    int n;
    vector<long long> t;

    static long long safe_gcd(long long a, long long b) {
        return __gcd(a, b);
    }

    void build(int v, int tl, int tr, const vector<long long> &a) {
        if (tl == tr) { t[v] = a[tl]; return; }
        int tm = (tl + tr) >> 1;
        build(v<<1, tl, tm, a);
        build(v<<1|1, tm+1, tr, a);
        t[v] = safe_gcd(t[v<<1], t[v<<1|1]);
    }

    void pointSet(int v, int tl, int tr, int pos, long long val) {
        if (tl == tr) { t[v] = val; return; }
        int tm = (tl + tr) >> 1;
        if (pos <= tm) pointSet(v<<1, tl, tm, pos, val);
        else pointSet(v<<1|1, tm+1, tr, pos, val);
        t[v] = safe_gcd(t[v<<1], t[v<<1|1]);
    }

    void pointAdd(int v, int tl, int tr, int pos, long long delta) {
        if (tl == tr) { t[v] += delta; return; }
        int tm = (tl + tr) >> 1;
        if (pos <= tm) pointAdd(v<<1, tl, tm, pos, delta);
        else pointAdd(v<<1|1, tm+1, tr, pos, delta);
        t[v] = safe_gcd(t[v<<1], t[v<<1|1]);
    }

    long long rangeGcd(int v, int tl, int tr, int l, int r) const {
        if (l > r) return 0; // identity
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr) >> 1;
        long long left = rangeGcd(v<<1, tl, tm, l, min(r, tm));
        long long right = rangeGcd(v<<1|1, tm+1, tr, max(l, tm+1), r);
        return __gcd(left, right);
    }

public:
    SegmentTree(): n(0) {}
    SegmentTree(const vector<long long> &a) { build(a); }

    void build(const vector<long long> &a) {
        n = (int)a.size();
        if (n == 0) { t.clear(); return; }
        t.assign(4*n, 0);
        build(1, 0, n-1, a);
    }

    // set a[pos] = val
    void set(int pos, long long val) {
        if (pos < 0 || pos >= n) return;
        pointSet(1, 0, n-1, pos, val);
    }

    // add delta to a[pos]
    void add(int pos, long long delta) {
        if (pos < 0 || pos >= n) return;
        pointAdd(1, 0, n-1, pos, delta);
    }

    // gcd on [l, r] inclusive
    long long gcd(int l, int r) const {
        if (n == 0 || l > r) return 0;
        l = max(l, 0); r = min(r, n-1);
        return rangeGcd(1, 0, n-1, l, r);
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<ll> temp;
        for(int i=1; i<n; i++) temp.push_back(abs(arr[i]-arr[i-1]));
        SegmentTree st(temp);
        for(int i=0; i<q; i++){
            int l, r;
            cin >> l >> r;
            l--; r-=2;
            ll ans = st.gcd(l, r);
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}