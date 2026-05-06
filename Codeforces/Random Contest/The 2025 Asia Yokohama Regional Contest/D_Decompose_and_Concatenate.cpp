#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll temp = 2e16;
    while(n < temp){
        temp /= 10;
    }
    cout << n-temp/2;
    cout << temp/2 << endl;
    return 0;
}