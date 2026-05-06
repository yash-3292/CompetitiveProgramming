#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        ll x;
        cin >> x;
        int is2power = 0;
        for(int i=0; i<30; i++){
            if(pow(2,i) == x){
                is2power = 1;
                break;
            }
        }
        if(is2power || x == 3){
            cout << "-1" << endl;
            continue;
        }
        if(x%2==1 && x%4!=3){
            cout << "3" << endl;
            continue;
        }
        for(int i=2; i<30; i++){
            ll power = pow(2,i);
            ll num = pow(2,i-1) + 1; 
            if(x % power != 0){
                if(x % power != num){
                    cout << num << endl;
                    break;
                } else if(x % power == num && num != 3){
                    cout << num + 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}