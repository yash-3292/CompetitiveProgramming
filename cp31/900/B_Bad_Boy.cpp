#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, i, j;
        cin >> n >> m >> i >> j;
        if(i == 1){
            cout << n << " " << 1 << " " << n << " " << m << endl;
        } else if(j == 1){
            cout << 1 << " " << m << " " << n << " " << m << endl;
        } else if(i == n){
            cout << 1 << " " << 1 << " " << 1 << " " << m << endl;
        } else if(j == m){
            cout << 1 << " " << 1 << " " << n << " " << 1 << endl;
        } else{
            cout << 1 << " " << 1 << " " << n << " " << m << endl;
        }
    }
    return 0;
}