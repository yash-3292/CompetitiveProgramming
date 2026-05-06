#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    vector<int> f(11);
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    for(int i=3; i<=10; i++){
        f[i] = f[i-1] + f[i-2];
    }
    while(t--){
        int n, m;
        cin >> n >> m;
        int x = f[n] + f[n-1];
        int y = f[n];
        while(m--){
            int w, l, h;
            cin >> w >> l >> h;
            int cnt = 0;
            if(w >= x) cnt++;
            if(l >= x) cnt++;
            if(h >= x) cnt++;
            int flag = 1;
            if(w < y) flag = 0;
            if(l < y) flag = 0;
            if(h < y) flag = 0;
            if(flag && cnt > 0){
                cout << 1;
            } else{
                cout << 0;
            }
        }
        cout << endl;
    }
    return 0;
}