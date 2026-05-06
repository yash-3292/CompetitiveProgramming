#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0; i<n; i++){
        if(i == 0){
            if(s[i] == '9') continue;
        }
        int num = s[i] - '0';
        s[i] = min(num, 9-num) + '0';
    }
    cout << s << endl;
    return 0;
}