#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        k--;
        if(n % 2 == 0){
            k = k % n;
            k++;
        } else{
            ll dif = n/2;
            k = k + k/dif;
            k = k % n;
            k++;
        }
        cout << k << endl;
    }
    return 0;
}