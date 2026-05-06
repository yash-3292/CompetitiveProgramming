#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    double n;
    cin >> n;
    double pi = 3.141592653589793;
    double ans = n * n * pi;
    ans /= 4;
    cout << setprecision(16) << ans << endl;
    return 0;
}