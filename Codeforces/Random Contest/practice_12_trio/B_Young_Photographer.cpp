#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, x;
    cin >> n >> x;
    int l = 0;
    int r = 1000;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        l = max(l, a);
        r = min(r, b);
    }
    if(l > r){
        cout << -1 << endl;
        return 0;
    }
    if(l <= x && x <= r){
        cout << 0 << endl;
    } else if(x < l){
        cout << l-x << endl;
    } else{
        cout << x-r << endl;
    }
    return 0;
}