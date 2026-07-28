#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int mini = 1e9;
    int ind = -1;
    for(int i=0; i<=k; i++){
        int o = i;
        int c = k-i;
        vector<int> skip(n, 0);
        for(int j=0; j<n; j++){
            if(s[j] == '(' && o > 0){
                o--;
                skip[j] = 1;
            }
        }
        for(int j=n-1; j>=0; j--){
            if(s[j] == ')' && c > 0){
                c--;
                skip[j] = 1;
            }
        }
        int val = 0;
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(skip[j]) continue;
            if(s[j] == '(') cnt++;
            else {
                if(cnt > 0){
                    cnt--;
                    val += 2;
                }
            }
        }
        if(val < mini){
            mini = val;
            ind = i;
        }
    }
    int o = ind;
    int c = k-ind;
    vector<int> skip(n, 0);
    for(int j=0; j<n; j++){
        if(s[j] == '(' && o > 0){
            o--;
            skip[j] = 1;
        }
    }
    for(int j=n-1; j>=0; j--){
        if(s[j] == ')' && c > 0){
            c--;
            skip[j] = 1;
        }
    }
    for(auto it : skip) cout << it;
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