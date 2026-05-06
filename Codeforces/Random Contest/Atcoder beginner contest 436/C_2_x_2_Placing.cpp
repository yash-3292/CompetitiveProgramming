#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    set<pair<int,int>> vis;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(vis.count({x,y}) || vis.count({x+1,y}) || vis.count({x,y+1}) || vis.count({x+1,y+1})) continue;
        ans++;
        vis.insert({x,y});
        vis.insert({x+1,y});
        vis.insert({x,y+1});
        vis.insert({x+1,y+1});
    }
    cout << ans << "\n";
}