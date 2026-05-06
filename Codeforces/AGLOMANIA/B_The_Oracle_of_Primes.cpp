#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        if(n == 1) n++;
        while(true){
            if(isPrime(n)) break;
            n++;
        }
        cout << n << endl;
    }
    return 0;
}