#include<bits/stdc++.h>
using namespace std;

int divi(int n){
    int x = 1;
    for(int i=3; i*i<=n; i++){
        if(n % i == 0){
            x = i;
            break;
        }
    }
    if(x == 1) return 1;
    return n/x * divi(x);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n&1){
            int x = divi(n);
            int y = n-x;
            cout << x << " " << y << endl;
        } else{
            int x = n/2;
            int y = n/2;
            cout << x << " " << y << endl;
        }
    }
    return 0;
}