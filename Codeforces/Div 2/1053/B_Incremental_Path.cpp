#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> arr(m);
    for(int i=0; i<m; i++) cin >> arr[i];
    int nw = 1e9+1;
    unordered_map<int,int> nextWhite;
    unordered_map<int,int> black;
    for(int i=m-1; i>=0; i--){
        if(i == m-1){
            nw = arr[i]+1;
        } else{
            if(arr[i]+1 != arr[i+1]) nw = arr[i]+1;
        }
        nextWhite[arr[i]] = nw;
        black[arr[i]] = 1;
    }
    int x = 1;
    for(int i=0; i<n; i++){
        if(s[i] == 'B'){
            if(black.find(x+1) == black.end()){
                x++;
            } else{
                x = nextWhite[x+1];
            }
            black[x] = 1;
            if(black.find(x+1) == black.end()){
                x++;
            } else{
                x = nextWhite[x+1];
            }
        } else{
            x++;
            black[x] = 1;
        }
    }
    vector<int> ans;
    for(auto it : black) ans.push_back(it.first);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto it : ans) cout << it << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}