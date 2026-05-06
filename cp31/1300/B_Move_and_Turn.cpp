#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n&1){
        int x = (n+1)/2;
        int ans = 2*x*(x+1);
        cout << ans << endl;
    } else{
        int x = (n/2) + 1;
        int ans = x*x;
        cout << ans << endl;
    }
    return 0;
}