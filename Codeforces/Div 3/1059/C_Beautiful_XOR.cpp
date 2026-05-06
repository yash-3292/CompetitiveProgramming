#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a == b){
            cout << 0 << endl;
            continue;
        }
        int ans1;
        int ans2 = -1;
        for(int i=31; i>=0; i--){
            if(a&(1<<i)){
                if(b&(1<<i)){
                    ans1 = (a^b);
                    break;
                } else{
                    ans1 = (a^b);
                    ans1 = (ans1^(1<<i));
                    ans2 = (1<<i);
                    break;
                }
            } else if(b&(1<<i)){
                ans1 = -1;
                break;
            }
        }
        if(ans1 == -1){
            cout << -1 << endl;
            continue;
        }
        if(ans2 == -1){
            cout << 1 << endl;
            cout << ans1 << endl;
        } else{
            cout << 2 << endl;
            cout << ans1 << " " << ans2 << endl;
        }
    }
    return 0;
}