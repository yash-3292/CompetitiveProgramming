#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int m = n;
        for(int i=0; i<n/2; i++){
            if(s[i] == s[n-i-1]) break;
            m -= 2;
        }
        cout << m << endl;
    }
    return 0;
}