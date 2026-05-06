#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        for(int i=0; i<n; i++) cin >> a[i]; 
        for(int i=0; i<m; i++) cin >> b[i];
        vector<int> freq(n+m+1, 0);
        sort(a.begin(), a.end());
        int sz = 0;
        for(int j=0; j<n; j++){
            if(j != 0 && a[j] == a[j-1]) continue;
            sz++;
            int val = a[j];
            for(int i=val; i<=n+m; i+=val){
                freq[i]++;
            }
        }
        int all = 0;
        int some = 0;
        int none = 0;
        for(int i=0; i<m; i++){
            if(freq[b[i]] == sz) all++;
            else if(freq[b[i]] == 0) none++;
            else some++;
        }
        int win;
        if(some&1){
            if(all >= none) win = 1;
            else win = 0;
        } else{
            if(all > none) win = 1;
            else win = 0;
        }
        if(win) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    return 0;
}