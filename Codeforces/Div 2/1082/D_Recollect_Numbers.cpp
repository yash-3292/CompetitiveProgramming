#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(int x){
    if(x == 1){
        cout << 1 << " " << 1 << endl;
        return;
    }
    cout << 1 << " " << 2 << " ";
    for(int i=3; i<=x; i++){
        cout << i << " " << i-2 << " ";
    }
    cout << x-1 << " " << x << endl;
}

void f1(int x, int n){
    for(int i=x+1; i<=n; i++){
        cout << i << " " << i << " ";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(n <= k && k <= 2*n-1){
            cout << "YES" << endl;
            f1(k-n+1, n);
            f(k-n+1);
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}