#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a == b){
            cout << "0 0" << endl;
        }
        else if(a > b){
            ll dif = a-b;
            ll move = b%dif;
            move = min(move, dif-move);
            cout << dif <<  " " << move << endl;
        }
        else{
            ll dif = b-a;
            ll move = a%dif;
            move = min(move, dif-move);
            cout << dif << " " << move << endl;
        }
    }
    return 0;
}