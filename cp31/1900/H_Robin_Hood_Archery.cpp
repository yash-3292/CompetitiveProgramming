#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int BLOCK_SIZE;

struct Query {
    int l, r, id;
    
    bool operator<(const Query& other) {
        int block_l = l / BLOCK_SIZE;
        int block_other_l = other.l / BLOCK_SIZE;
        
        if(block_l != block_other_l){
            return block_l < block_other_l;
        }

        return (block_l % 2 == 1) ? r < other.r : r > other.r;
    }
};

const int MAXN = 1e6+10;
int arr[MAXN];
int freq[MAXN];
int odd_cnt = 0;

void add(int idx){
    freq[arr[idx]] = 1 - freq[arr[idx]];
    if(freq[arr[idx]]) odd_cnt++;
    else odd_cnt--;
}

void remove(int idx){
    freq[arr[idx]] = 1 - freq[arr[idx]];
    if(freq[arr[idx]]) odd_cnt++;
    else odd_cnt--;
}

void solve(){
    int n, q;
    cin >> n >> q;
    BLOCK_SIZE = sqrt(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<Query> queries(q);
    for(int i=0; i<q; i++){
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].id = i;
    }
    sort(queries.begin(), queries.end());

    vector<int> ans(q);
    int L = 0, R = -1;

    for(int i=0; i<q; i++){
        int ql = queries[i].l;
        int qr = queries[i].r;

        while(L > ql) add(--L);
        while(R < qr) add(++R);
        while(L < ql) remove(L++);
        while(R > qr) remove(R--);

        ans[queries[i].id] = odd_cnt;
    }

    while(L <= R){
        remove(L++);
    }
    odd_cnt = 0;

    for(int i=0; i<q; i++){
        if(ans[i] == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<MAXN; i++) freq[i] = 0;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}