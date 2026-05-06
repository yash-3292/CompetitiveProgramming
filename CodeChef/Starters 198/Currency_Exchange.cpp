#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        int val1 = a1*5 + b1;
        int val2 = a2*5 + b2;
        if(val1%6 == val2%6 && val1 >= val2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}