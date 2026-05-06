#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define x first
#define y second

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        vector<pair<ll,ll>> city(n);
        for(int i=0; i<n; i++){
            cin >> city[i].x >> city[i].y;
        }
        ll minDis1;
        ll minDis2;
        if(a <= k) minDis1 = 0;
        else{
            minDis1 = LLONG_MAX;
            for(int i=0; i<k; i++){
                ll dis = abs(city[i].x - city[a-1].x) + abs(city[i].y - city[a-1].y);
                minDis1 = min(minDis1, dis);
            }
        }
        if(b <= k) minDis2 = 0;
        else{
            minDis2 = LLONG_MAX;
            for(int i=0; i<k; i++){
                ll dis = abs(city[i].x - city[b-1].x) + abs(city[i].y - city[b-1].y);
                minDis2 = min(minDis2, dis);
            }
        }
        ll minDis;
        if(k != 0) minDis = minDis1 + minDis2;
        else minDis = LLONG_MAX;
        if(a > k && b > k){
            ll dis = abs(city[a-1].x - city[b-1].x) + abs(city[a-1].y - city[b-1].y);
            minDis = min(minDis, dis);
        }
        cout << minDis << endl;
    }
    return 0;
}