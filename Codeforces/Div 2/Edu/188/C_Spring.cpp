#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, c, m;
        cin >> a >> b >> c >> m;
        ll lcmab = (a*b)/__gcd(a,b);
        ll lcmbc = (b*c)/__gcd(b,c);
        ll lcmca = (c*a)/__gcd(c,a);
        ll lcmabc = (lcmab*c)/__gcd(lcmab,c);
        ll x = (m/a - m/lcmab - m/lcmca + m/lcmabc)*6 + (m/lcmab + m/lcmca - 2*(m/lcmabc))*3 + (m/lcmabc)*2;
        ll y = (m/b - m/lcmab - m/lcmbc + m/lcmabc)*6 + (m/lcmab + m/lcmbc - 2*(m/lcmabc))*3 + (m/lcmabc)*2;
        ll z = (m/c - m/lcmbc - m/lcmca + m/lcmabc)*6 + (m/lcmbc + m/lcmca - 2*(m/lcmabc))*3 + (m/lcmabc)*2;
        cout << x << " " << y << " " << z << endl;
    }
    return 0;
}