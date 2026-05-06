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

        vector<vector<vector<ll>>> vis(200, vector<vector<ll>>(200, vector<ll>(4,-1)));
        int flag = 1;

        ll distance = 0;
        
        while(distance < d){
            if(flag && vis[x][y][dir] != -1){
                d = (d-vis[x][y][dir])%(distance - vis[x][y][dir]);
                distance = 0;
                flag = 0;
            }
            if(dir == 0){
                if(mppY.find(y) == mppY.end() || mppY[y].empty()){
                    x = x+d-distance;
                    distance = d;
                }
                else{
                    auto it = mppY[y].lower_bound(x);
                    if(it == mppY[y].end()){
                        x = x+d-distance;
                        distance = d;
                    } else{
                        ll val = (ll)(*it-x-1);
                        if(val >= d-distance){
                            x = x + d-distance;
                            distance = d;
                        } else{
                            if(val > 0) vis[x][y][dir] = distance;
                            x = x+val;
                            distance = distance+val;
                        }
                    }
                }
            } else if(dir == 1){
                if(mppX.find(x) == mppX.end() || mppX[x].empty()){
                    y = y+d-distance;
                    distance = d;
                } else{
                    auto it = mppX[x].lower_bound(y);
                    if(it == mppX[x].end()){
                        y = y+d-distance;
                        distance = d;
                    } else{
                        ll val = (ll)(*it-y-1);
                        if(val >= d-distance){
                            y = y + d-distance;
                            distance = d;
                        } else{
                            if(val > 0) vis[x][y][dir] = distance;
                            y = y+val;
                            distance = distance+val;
                        }
                    }
                }
            } else if(dir == 2){
                if(mppY.find(y) == mppY.end() || mppY[y].empty()){
                    x = x-(d-distance);
                    distance = d;
                } else{
                    auto it = mppY[y].lower_bound(x);
                    if(it == mppY[y].begin()){
                        x = x-(d-distance);
                        distance = d;
                    } else{
                        it--;
                        ll val = (ll)(x-*it-1);
                        if(val >= d-distance){
                            x = x - (d-distance);
                            distance = d;
                        } else{
                            if(val > 0) vis[x][y][dir] = distance;
                            x = x-val;
                            distance = distance+val;
                        }
                    }
                }
            } else{
                if(mppX.find(x) == mppX.end() || mppX[x].empty()){
                    y = y-(d-distance);
                    distance = d;
                } else{
                    auto it = mppX[x].lower_bound(y);
                    if(it == mppX[x].begin()){
                        y = y-(d-distance);
                        distance = d;
                    } else{
                        it--;
                        ll val = (ll)(y-*it-1);
                        if(val >= d-distance){
                            y = y -(d-distance);
                            distance = d;
                        } else{
                            if(val > 0) vis[x][y][dir] = distance;
                            y = y-val;
                            distance = distance+val;
                        }
                    }
                }
            }
            dir = (dir+1)%4;
        }

        cout << x << " " << y << " " << endl;
    }
    return 0;
}