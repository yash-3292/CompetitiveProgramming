#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = stoi(s);
        int x = (int)sqrt(n);
        if(x*x != n){
            cout << -1 << endl;
            continue;
        }
        if(x == 0){
            cout << 0 << " " << 0 << endl;
            continue;
        }
        cout << 1 << " " << x-1 << endl;
    }
    return 0;
}