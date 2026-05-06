#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int moves = 0;
        if(d < b){
            cout << -1 << endl;
            continue;
        }
        moves += d - b;
        a += moves;
        b += moves;
        if(a < c){
            cout << -1 << endl;
            continue;
        }
        moves += a - c;
        cout << moves << endl;
    }
    return 0;
}