#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isValid(string s){
    int val = 0;
    for(auto ch : s){
        if(ch == '(') val++;
        else val--;
        if(val < 0) return false;
    } 
    if(val != 0) return false;
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int a = 0;
        int b = 0;
        for(auto ch : s){
            if(ch == '(') a++;
            else if(ch == ')') b++;
        }
        if(a > n/2 || b > n/2){
            cout << "NO" << endl;
            continue;
        }
        int x = n/2 - a;
        int lo = -1;
        int fc = -1; 
        for(int i=0; i<n; i++){
            if(s[i] == '?'){
                if(x > 0){
                    s[i] = '(';
                    lo = i;
                    x--;
                } else {
                    s[i] = ')';
                    if(fc == -1) fc = i;
                }
            }
        }
        if(!isValid(s)){
            cout << "NO" << endl;
            continue;
        }
        if(lo != -1 && fc != -1){
            swap(s[lo], s[fc]);
            if(isValid(s)){
                cout << "NO" << endl;
                continue;
            }
        }
        cout << "YES" << endl;
    }
    return 0;
}