#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define f(i, a, b) for (ll i = a; i <= b; ++i)
#define rf(i, a, b) for (ll i = a; i >= b; --i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define endl '\n'

const ll MOD = 1e9 + 7;
const ll INF = 1e18; 

void fastIO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll xl1,yl1,xr1,yr1;
ll x11,y11,x21,y21;
double mx,my;
bool ch(ll a,ll b) {
    double t1 = ((x21 -x11) * b) - ((y21-y11) * a) + x11 - (y11*(x21-x11));
    double t2 = ((x21 -x11) * my) -((y21-y11) * mx) + x11 - (y11*(x21-x11));
    cout << t1 << " " << t2 << "  ";
    if(t1 == 0 || t2 == 0){
        cout << "hi ";
        return false;
    } 
    return (t1<0 && t2<0) || (t1>0 && t2>0);
}
void solve() {
    ll xl,yl,xr,yr;
    ll x1,y1,x2,y2;
    cin>>xl>>yl>>xr>>yr;
    cin>>x1>>y1>>x2>>y2;
    xl1 = xl;
    yl1 = yl;
    xr1 = xr;
    yr1 = yr;
    x11=x1;
    y11=y1;
    x21=x2;
    y21 = y2;
    ll cnt = 0;
    if(x1<=x2) {
        if(!(x2<xl || x1>xr)) {
            cnt++;
        } 
    }
    else {
        if(!(x1<xl || x2>xr)) {
            cnt++;
        } 
    }
    if(y1<=y2) {
        if(!(y2<yl || (y1>yr))) {
            cnt++;
        } 
    }
    else {
        if(!(y1<yl || y2>yr)) {
            cnt++;
        } 
    }

    if(cnt==2) {
        mx = (double(xl) + double(xr)) /2;
        my = (double(yl) + double(yr)) /2;
        bool ch1 = ch(xl,yl) & ch(xl + (xr-xl) , yl) & ch(xl,yl+(yr-yl)) & ch(xl + (xr-xl) , yl + (yr-yl));
        cout << endl;
        if(!ch1) {
            cout<<"OK\n";
        } 
        else {
            cout<<"STOP\n";
        }

    }
    else cout<<"OK\n";

}

int main() {
    fastIO();

    ll t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}