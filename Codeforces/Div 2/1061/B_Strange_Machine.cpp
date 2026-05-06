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
        int allA = 1;
        for(int i=0; i<n; i++){
            if(s[i] == 'B'){
                allA = 0;
                break;
            }
        }
        if(allA){
            while(q--){
                int x;
                cin >> x;
                cout << x << endl;
            }
        } else{
            while(q--){
                int x;
                cin >> x;
                int temp = x;
                int t = 0;
                while(temp > 0){
                    if(s[t%n] == 'A'){
                        temp--;
                    } else{
                        temp /= 2;
                    }
                    t++;
                }
                cout << t << endl;
            }
        }
    }
    return 0;
}