#include<bits/stdc++.h>
using namespace std;

int findA(int n){
    int a = 1;
    for(int i=3; i*i<=n; i+=2){
        if(n%i == 0){
            a = i;
            break;
        }
    }
    if(a == 1) return 1;
    return n/a * findA(a);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2 == 0){
            cout << n/2 << " " << n/2 << endl;
            continue;
        } 
        int a = findA(n);
        cout << a << " " << n-a << endl;
    }
    return 0;
}