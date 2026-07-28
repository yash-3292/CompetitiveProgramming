#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int query(int x){
    cout << "? " << x+1 << "\n";
    cout << flush;
    int ans;
    cin >> ans;
    return ans;
}

void fans(int a, int b){
    cout << "! " << a << " " << b << "\n";
    cout << flush;
}

void wrans(){
    cout << "! -1" << "\n";
    cout << flush;
}

void solve(){
    int n, k;
    cin >> n >> k;
    if(n == 2*k){
        fans(k,k);
        return;
    }
    vector<int> a(k);
    vector<int> b(k);
    for(int i=0; i<k; i++){
        a[i] = query(i);
    }
    for(int i=n-k; i<n; i++){
        b[(i%k)] = query(i);
    }
    int ind = -1;
    for(int i=0; i<k; i++){
        if(a[i] != b[i]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        wrans();
        return;
    }
    int l = 0;
    int r = n/k;
    int ans = 0;
    while(l <= r){
        int mid = l + (r-l)/2;
        int i = (mid)*k + ind;
        if(i >= n){
            r = mid-1;
            continue;
        }
        if(query(i) == a[ind]){
            ans = mid;
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
    l = ans*k + ind;
    r = l + k;
    vector<pair<char,int>> s;
    s.push_back({'a',l});
    for(int i=l+1; i<=r; i++){
        if(i <= k-1) continue;
        if(i >= n-k) continue;
        int val = query(i);
        if(val == a[(i%k)] && val == b[(i%k)]){
            s.push_back({'u',i});
        } else if(val == a[(i%k)]){
            s.push_back({'a',i});
        } else{
            s.push_back({'b',i});
        }
    }
    int bind = s.back().second+1;
    int ucnt = 0;
    for(auto it : s){
        if(it.first == 'b'){
            bind = min(bind, it.second);
        } else if(it.first == 'a'){
            ucnt = 0;
        } else{
            if(it.second < bind) ucnt = 1;
        }
    } 
    if(ucnt){
        wrans();
        return;
    }
    fans(bind, n-bind);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}