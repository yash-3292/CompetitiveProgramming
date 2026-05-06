#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y, z;
        cin >> x >> y >> z;
        if(z >= x){
            cout << "Yes" << endl;
            continue;
        }
        if(y == 0){
            if(z == x-1){
                cout << "Yes" << endl;
                continue;
            }
        } 
        cout << "No" << endl;
    }
    return 0;
}