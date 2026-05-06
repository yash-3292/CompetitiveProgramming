#include<bits/stdc++.h>
using namespace std;

int main(){
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    int e1s = (a1*a3)/a2;

    int a = round(sqrt(e1s));
    int b = a1/a;
    int c = a3/a;

    int ans = (a+b+c)*4;

    cout << ans << endl;
    return 0;
}