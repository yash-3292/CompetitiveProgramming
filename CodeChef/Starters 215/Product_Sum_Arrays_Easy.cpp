#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int isPrime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i == 0) return i;
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int val = isPrime(n);
        if(val == -1){
            cout << 1 << endl;
            continue;
        } 
        if(isPrime(val) == -1 && isPrime(n/val) == -1){
            cout << 2 << endl;
        } else{
            cout << 3 << endl;
        }
    }
    return 0;
}