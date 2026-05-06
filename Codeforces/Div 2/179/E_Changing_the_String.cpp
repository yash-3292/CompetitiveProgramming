#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        int i = 0;
        int j = 0;
        while(s[i] != 'b' && i != n) i++;
        while(s[j] != 'c' && j != n) j++;
        while(q--){
            char x, y;
            cin >> x >> y;
            if(x == 'c' && y == 'a'){
                if(j != n){
                    s[j] = 'a';
                    while(s[j] != 'c' && j != n) j++;
                }
            } else if(x == 'b' && y == 'a'){
                if(i != n){
                    s[i] = 'a';
                    while(s[i] != 'b' && i != n) i++;
                }
            } else if(x == 'c' && y == 'b'){
                if(j != n){
                    s[j] = 'b';
                    if(j < i) i = j;
                    while(s[j] != 'c' && j != n) j++;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}