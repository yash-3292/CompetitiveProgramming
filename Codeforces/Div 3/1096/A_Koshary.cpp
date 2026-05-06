#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        if((x&1) && (y&1)){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    }
    return 0;
}