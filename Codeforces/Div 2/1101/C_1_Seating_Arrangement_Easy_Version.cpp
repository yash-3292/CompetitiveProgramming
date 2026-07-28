#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, x, s;
    cin >> n >> x >> s;
    string u;
    cin >> u;
    int ans = 0;
    for(int i=0; i<=x; i++){
        int amb = i;
        int intr = x - i;
        int extr = 0;
        int val = 0;
        for(auto ch : u){
            if(ch == 'A'){
                if(amb > 0){
                    amb--;
                    val++;
                    extr += s-1;
                } else if(extr > 0){
                    extr--;
                    val++;
                }
            } else if(ch == 'I'){
                if(intr > 0){
                    intr--;
                    extr += s-1;
                    val++;
                }
            } else{
                if(extr > 0){
                    extr--;
                    val++;
                }
            }
        }
        ans = max(ans, val);
    }
    cout << ans << endl;
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