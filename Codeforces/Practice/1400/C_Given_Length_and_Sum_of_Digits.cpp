#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int m, s;
    cin >> m >> s;
    if(s == 0 || s > 9*m){
        if(s == 0 && m == 1) cout << 0 << " " << 0 << endl;
        else cout << -1 << " " << -1 << endl;
        return 0;
    } 
    string mini(m, '0'), maxi(m, '0');
    mini[0] = '1';
    maxi[0] = '1';
    int cnt = s-1;
    for(int i=m-1; i>=0; i--){
        int val = '9' - mini[i];
        if(cnt >= val){
            mini[i] += val;
            cnt -= val;
        } else{
            mini[i] += cnt;
            cnt = 0;
        }
        if(!cnt) break;
    } 
    cnt = s-1;
    for(int i=0; i<m; i++){
        int val = '9' - maxi[i];
        if(cnt >= val){
            maxi[i] += val;
            cnt -= val;
        } else{
            maxi[i] += cnt;
            cnt = 0;
        }
        if(!cnt) break;
    } 
    cout << mini << " " << maxi << endl;
    return 0;
}