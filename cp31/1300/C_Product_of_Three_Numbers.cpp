#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int nf = 1;
        int a;
        int b;
        int c;
        for(int i=2; i*i<=n; i++){
            if(n%i == 0){
                nf = 0;
                a = i;
                break;
            }
        }
        if(nf){
            cout << "NO" << endl;
            continue;
        }
        n /= a;
        nf = 1;
        for(int i=2; i*i<n; i++){
            if(i == a) continue;
            if(n%i == 0){
                nf = 0;
                b = i;
                break;
            }
        }
        if(nf){
            cout << "NO" << endl;
            continue;
        }
        n /= b;
        if(n <= 1){
            cout << "NO" << endl;
            continue;
        }
        c = n;
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}