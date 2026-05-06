#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2){
        if(x1 == 1e9){
            cout << x1-1 << " " << y1 << endl;
        } else{
            cout << x1+1 << " " << y1 << endl;
        }
    } else if(y1 == y2){
        if(y1 == 1e9){
            cout << x1 << " " << y1-1 << endl;
        } else{
            cout << x1 << " " << y1+1 << endl;
        }
    } else{
        cout << x1 << " " << y2 << endl;
    }
    return 0;
}