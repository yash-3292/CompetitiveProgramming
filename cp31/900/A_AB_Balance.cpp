#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        if(n == 1){
            cout << s << endl;
            continue;
        }
        if(s[0] != s[n-1]){
            s[n-1] = s[0];
        }
        cout << s << endl;
    }
    return 0;
}