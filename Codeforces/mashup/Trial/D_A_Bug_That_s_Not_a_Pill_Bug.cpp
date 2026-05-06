#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        ll a, b, d;
        cin >> a >> b >> d;

        map<int,set<int>> mppX;
        map<int,set<int>> mppY;

        for(int i=0; i<n; i++){
            int x, y;
            cin >> x >> y;
            mppX[x].insert(y);
            mppY[y].insert(x);
        }

        ll x = a;
        ll y = b;
        ll dir = 0;

        vector<vector<int>> vis(200, vector<int>(200, 0));
        int flag = 1;

        ll distance = 0;
        
        while(distance < d){
            if(flag && vis[x][y]){
                d = d%distance;
                distance = 0;
                flag = 0;
            }
            if(dir == 0){
                auto it = mppY[y].lower_bound(x);
                if(it == mppX[x].end()){
                    y = y+d-distance;
                    distance = d;
                } else{
                    
                }
            } else if(dir == 1){

            } else if(dir == 2){

            } else{

            }
            vis[x][y] = 1;
            dir = (dir+1)%4;
            break;
        }

        cout << x << " " << y << endl;
    }
    return 0;
}