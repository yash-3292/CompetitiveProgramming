#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, n;
        cin >> a >> b >> n;
        if(a/b >= n){
            cout << 1 << endl;
        } else if(a == b){
            cout << 1 << endl;
        } else{
            cout << 2 << endl;
        }
    }
    return 0;
}