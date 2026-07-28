#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<string> arr(k, "");
    for(int i=0; i<n; i++){
        int ind = i%k;
        arr[ind] += s[i];
    }
    for(auto it : arr){
        int m = it.size();
        for(int i=m-1; i>=0; i--){
            if(i == 0){
                if(it[i] == '1'){
                    cout << "NO" << endl;
                    return;
                }
            } else{
                if(it[i] == '1'){
                    it[i] = '0';
                    if(it[i-1] == '1') it[i-1] = '0';
                    else it[i-1] = '1';
                }
            }
        }
    }
    cout << "YES" << endl;
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