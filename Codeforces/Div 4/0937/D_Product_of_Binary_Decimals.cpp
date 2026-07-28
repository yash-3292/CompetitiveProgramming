#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> val;

void f(){
    for(int i=2; i<32; i++){
        int x = 0;
        for(int j=4; j>=0; j--){
            x = x*10 + ((i>>j)&1);
        }
        if(x%10 == 0) continue;
        val.push_back(x);
    }
    reverse(val.begin(), val.end());
}

void solve(){
    int n;
    cin >> n;
    while(n%10 == 0) n/=10;
    while(n != 1){
        int flag = 0;
        for(auto it : val){
            if(n%it == 0){
                n/=it;
                flag = 1;
            }
        }
        if(!flag){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    f();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}