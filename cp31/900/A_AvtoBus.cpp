#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;  
        if(n&1 || n==2){
            cout << -1 << endl;
            continue;
        }
        ll maxi = n/4;
        ll mini = n/6;
        if(n%6 == 2 || n%6 == 4) mini++;
        cout << mini << " " << maxi << endl;
    }
    return 0;
}
