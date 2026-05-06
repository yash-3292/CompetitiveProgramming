#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if(((x&(x-1)) == 0) || ((x&(x+1)) == 0)){
            cout << -1 << endl;
            continue;
        }
        int flag = 0;
        for(int i=31; i>=0; i--){
            if(flag){
                if(!(x&(1<<i))){
                    x |= (1<<i);
                    break;
                }
            } else{
                if((x&(1<<i))){
                    flag = 1;
                    x = (x^(1<<i));
                }
            }
        }
        cout << x << endl;
    }
    return 0;
}