#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(int n){
    cout << n << " ";
    for(int i=2; i<n; i+=2){
        cout << i+1 << " " << i << " ";
    }
    cout << 1 << " ";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n&1){
            f(n-1);
            cout << n << " ";
        } else{
            f(n);
        }
        cout << endl;
    }
    return 0;
}