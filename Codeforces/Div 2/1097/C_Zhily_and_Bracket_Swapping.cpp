#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0; i<n; i++){
        if(a[i] == b[i]){
            if(a[i] == '('){
                cnt1++;
                cnt2++;
            } else{
                cnt1--;
                cnt2--;
            }
        } else{
            if(cnt1 > cnt2){
                cnt1--;
                cnt2++;
            } else{
                cnt1++;
                cnt2--;
            }
        }
        if(cnt1 < 0 || cnt2 < 0){
            cout << "NO" << endl;
            return;
        }
    }
    if(cnt1 == 0 && cnt2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}