#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int val = 0;
    for(int i=n; i>=0; i--){
        int x;
        cin >> x;
        if(x){
            val = (val|(1<<i));
        }
    }
    int ans = 0;
    while(val != 1){
        if(val&1){
            val = ((val)^(val<<1));
            val = (val^1);
        } else{
            val = (val>>1);
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}