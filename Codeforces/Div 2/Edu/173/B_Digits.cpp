#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, d;
    cin >> n >> d;
    vector<int> ans;
    ans.push_back(1);
    if(n >= 3 || d%3 == 0) ans.push_back(3);
    if(d%5 == 0) ans.push_back(5);
    if(n >= 3 || d%7 == 0) ans.push_back(7);
    if(d == 9) ans.push_back(9);
    else if(n >= 3 && d%3 == 0) ans.push_back(9);
    else if(n >= 6) ans.push_back(9);
    for(auto it : ans) cout << it << " ";
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