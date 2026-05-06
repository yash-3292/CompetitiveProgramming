#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    int flag = 0;
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]) cnt++;
        else cnt = 0;
        if(cnt >= 6) flag = 1;
    }
    if(flag){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    return 0;
}