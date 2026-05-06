#include<bits/stdc++.h>
using namespace std;

int main(){
    int y, w;
    cin >> y >> w;

    int x = max(y, w);
    x = 6 - x + 1;
    int i = 6;

    int gcd = __gcd(x, i);

    x /= gcd;
    i /= gcd;

    cout << x << "/" << i << endl;
    return 0;
}