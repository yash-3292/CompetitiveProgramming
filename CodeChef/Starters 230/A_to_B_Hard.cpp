#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a, b;
        cin >> a;
        cin >> b;
        int zero1 = 0;
        int zero2 = 0;
        for(int i=0; i<n; i++) if(a[i] == '0') zero1++;
        for(int i=0; i<n; i++) if(b[i] == '0') zero2++;
        int flag1 = (zero1 == 0 || zero1 == n);
        int flag2 = (zero2 == 0 || zero2 == n);
        if(zero1 == 0 && zero2 == n){
            cout << 1 << endl;
        } else if(zero1 == n && zero2 == 0){
            cout << 1 << endl;
        } else if(flag1 && (!flag2)){
            cout << 1 << endl;
        } else if((!flag1) && flag2){
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}