#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]){
            if(s[i-1] != 'a' && (i+1 >= n || s[i+1] != 'a')) s[i] = 'a';
            else if(s[i-1] != 'b' && (i+1 >= n || s[i+1] != 'b')) s[i] = 'b';
            else s[i] = 'c';
        }
    }
    cout << s << endl;
    return 0;
}