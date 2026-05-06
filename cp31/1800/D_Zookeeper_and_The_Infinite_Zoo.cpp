#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        bitset<31> ub(u);
        bitset<31> vb(v);
        int l = 0;
        int r = 0;
        int flag = 1;
        for(int i=0; i<30; i++){
            if(ub[i] == 0 && vb[i] == 0){
            } else if(ub[i] == 0 && vb[i] == 1){
                if(r==0){
                    flag = 0;
                    break;
                }
                l = 0;
                r--;
            } else if(ub[i] == 1 && vb[i] == 0){
                l++;
                r++;
            } else{
                if(l > 0) l = 1;
                else l = 0;
            }
        }
        if(l > 0) flag = 0;
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}