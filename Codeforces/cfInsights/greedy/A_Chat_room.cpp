#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string t = "hello";
    int n = s.size();
    int m = t.size();
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(s[i] == t[j]){
            i++;
            j++;
        } else{
            i++;
        }
    }
    if(j == m) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}