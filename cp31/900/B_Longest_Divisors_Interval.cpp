#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll k = 1;
        while(true){
            if(n%(k+1) != 0){
                break;
            }
            k++;
        }
        cout << k << endl;
    }
    return 0;
}