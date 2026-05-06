#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, m;
        cin >> n >> x >> m;
        pair<int,int> curr = {x,x};
        while(m--){
            pair<int,int> p;
            cin >> p.f >> p.s;
            if(!(curr.s < p.f) && !(p.s < curr.f)){
                curr.f = min(curr.f, p.f);
                curr.s = max(curr.s, p.s);
            }
        } 
        int ans = curr.s - curr.f + 1;
        cout << ans << endl;
    }
    return 0;
}