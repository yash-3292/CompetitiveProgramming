#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    vector<int> nextSingle(n), nextDouble(n);
    vector<int> posSingle(n+2, n), posDouble(n+2, n);
    vector<int> nextSingleOne(n), nextDoubleOne(n);
    int singleOne = n;
    int doubleOne = n;
    for(int i=n-1; i>=0; i--){
        if(a[i] == b[i]){
            nextDouble[i] = posDouble[a[i]+1];
            nextSingle[i] = posSingle[a[i]+1];
            posDouble[a[i]] = i;
            nextSingleOne[i] = singleOne;
            nextDoubleOne[i] = doubleOne;
            if(a[i] == 1){
                doubleOne = i;
            }
        } else{
            nextDouble[i] = posDouble[1];
            nextSingle[i] = posSingle[1];
            posSingle[a[i]] = i;
            posSingle[b[i]] = i;
            nextSingleOne[i] = singleOne;
            nextDoubleOne[i] = doubleOne;
            if(a[i] == 1 || b[i] == 1){
                singleOne = i;
            }
        }
    }
    vector<int> ans(n+1);
    ans[n] = n;
    for(int i=n-1; i>=0; i--){
        if(nextSingle[i] < nextDouble[i]){
            ans[i] = nextSingle[i];
        } else{
            ans[i] = ans[nextDouble[i]];
        }
    }
    ll val = 0;
    for(int i=0; i<n; i++){
        if(a[i] == 1 && b[i] != 1) continue;
        if(a[i] != 1 && b[i] == 1) continue;
        if(a[i] == 1 && b[i] == 1){
            val += ans[i] - i;
        } else{
            if(nextSingleOne[i] < nextDoubleOne[i]){
                val += nextSingleOne[i] - i;
            } else{
                val += ans[nextDoubleOne[i]] - i;
            }
        }
    }
    // cout << endl;
    cout << val << endl;
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