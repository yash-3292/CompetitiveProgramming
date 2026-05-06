#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long int

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a < b) swap(a, b);
        if(a % b != 0){
            cout << -1 << endl;
            continue;
        }
        int num = a / b;
        int x = (int)log2(num);
        if((int)pow(2,x) != num){
            cout << -1 << endl;
            continue;
        }
        int oper = x / 3;
        if(x % 3 != 0) oper++;
        cout << oper << endl;
    }
    return 0;
}