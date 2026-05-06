#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        string s;
        cin >> n;
        cin >> s;
        int consDot = 0;
        int totalDot = 0;
        int dot = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '.'){
                totalDot++;
                dot++;
            } else{
                dot = 0;
            }
            consDot = max(consDot, dot);
        }
        if(consDot >= 3){
            cout << 2 << endl;
        } else{
            cout << totalDot << endl;
        }
    }
    return 0;
}