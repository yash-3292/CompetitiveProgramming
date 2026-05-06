#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char c;
        cin >> c;
        string s;
        cin >> s;
        int flag = 1;
        for(int i=0; i<n; i++){
            if(s[i] != c){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << 0 << endl;
            continue;
        }
        flag = 0;
        int i;
        for(i=n-1; i+1>n/2; i--){
            if(s[i] == c){
                flag = 1;
                break;
            }
        }
        if(flag){
            cout << 1 << endl;
            cout << i+1 << endl;
        } else{
            cout << 2 << endl;
            cout << n-1 << " " << n << endl;
        }
    }
    return 0;
}