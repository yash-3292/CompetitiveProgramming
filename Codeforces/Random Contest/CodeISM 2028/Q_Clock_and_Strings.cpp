#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int cnt = 0;
        if(a > b) swap(a, b);
        if(a < c  && c < b) cnt++;
        if(a < d  && d < b) cnt++;
        // cout << cnt << " ";
        if(cnt == 1){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}