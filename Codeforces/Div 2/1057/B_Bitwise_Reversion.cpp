#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y, z;
        cin >> x >> y >> z;
        int a = (x | z);
        int b = (x | y);
        int c  = (y | z);
        int flag = 1;
        if((a&b) != x) flag = 0;
        if((b&c) != y) flag = 0;
        if((c&a) != z) flag = 0;
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}