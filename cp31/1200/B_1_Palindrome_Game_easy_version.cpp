#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int zero = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '0') zero++;
        }
        if(zero&1){
            if(zero == 1) cout << "BOB" << endl;
            else cout << "ALICE" << endl;
        } else{
            cout << "BOB" << endl;
        }
    }
    return 0;
}