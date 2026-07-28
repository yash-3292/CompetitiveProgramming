#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    int mx_zero;
    int cnt_ones;
};

class SegTree {
    int n;
    vector<Node> tree;
    vector<int> lazy;

    Node merge(const Node& a, const Node& b) {
        Node res;
        res.mx_zero = max(a.mx_zero, b.mx_zero);
        res.cnt_ones = a.cnt_ones + b.cnt_ones;
        return res;
    }

    void apply(int id, int l, int r, int val) {
        if (val == 0) {
            tree[id].mx_zero = r;
            tree[id].cnt_ones = 0;
        } else {
            tree[id].mx_zero = -1;
            tree[id].cnt_ones = (r - l + 1);
        }
        lazy[id] = val;
    }

    void push(int id, int l, int r) {
        if (lazy[id] != -1) {
            int mid = l + (r - l) / 2;
            apply(2 * id + 1, l, mid, lazy[id]);
            apply(2 * id + 2, mid + 1, r, lazy[id]);
            lazy[id] = -1;
        }
    }

    void build(int id, int l, int r, const vector<int>& arr) {
        if (l == r) {
            tree[id].mx_zero = (arr[l] == 0) ? l : -1;
            tree[id].cnt_ones = (arr[l] == 1) ? 1 : 0;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * id + 1, l, mid, arr);
        build(2 * id + 2, mid + 1, r, arr);
        tree[id] = merge(tree[2 * id + 1], tree[2 * id + 2]);
    }

    void update_range(int id, int l, int r, int ql, int qr, int val) {
        if (l > qr || r < ql) return;
        if (l >= ql && r <= qr) {
            apply(id, l, r, val);
            return;
        }
        push(id, l, r);
        int mid = l + (r - l) / 2;
        update_range(2 * id + 1, l, mid, ql, qr, val);
        update_range(2 * id + 2, mid + 1, r, ql, qr, val);
        tree[id] = merge(tree[2 * id + 1], tree[2 * id + 2]);
    }

    Node query_range(int id, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return {-1, 0};
        if (l >= ql && r <= qr) return tree[id];
        push(id, l, r);
        int mid = l + (r - l) / 2;
        return merge(query_range(2 * id + 1, l, mid, ql, qr), 
                     query_range(2 * id + 2, mid + 1, r, ql, qr));
    }

public:
    SegTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.assign(4 * n, -1);
        build(0, 0, n - 1, arr);
    }

    void update(int ql, int qr, int val) {
        update_range(0, 0, n - 1, ql, qr, val);
    }

    int maxZero(int ql, int qr) {
        return query_range(0, 0, n - 1, ql, qr).mx_zero;
    }

    int countOne(int ql, int qr) {
        return query_range(0, 0, n - 1, ql, qr).cnt_ones;
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n, 0);
    SegTree seg(arr);
    int one = 0;
    while(q--){
        int t;
        cin >> t;
        if(t == 0){
            int l, r;
            cin >> l >> r;
            l--; r--;
            seg.update(l, r, 0);
        } else if(t == 1){
            int l, r;
            cin >> l >> r;
            l--; r--;
            seg.update(l, r, 1);
        } else{
            int one = seg.countOne(0, n-1);
            int zero = n - one;
            if(zero){
                seg.update(0, zero-1, 0);
            }
            if(one){
                seg.update(zero, n-1, 1);
            }
        }
        int ans = seg.countOne(0, n-1) - (n - 1 - seg.maxZero(0, n-1));
        cout << ans+1 << endl;
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