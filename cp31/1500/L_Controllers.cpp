#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int plus = 0;
    int minus = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '+') plus++;
        else minus++;
    }
    if(plus == minus){
        int q;
        cin >> q;
        while(q--){
            int a,b;
            cin >> a >> b;
            cout << "YES" << endl;
        }
    } else{
        map<pair<int,int>,int> freq;
        while(plus && minus){
            int gcd = __gcd(plus, minus);
            int x = plus/gcd;
            int y = minus/gcd;
            freq[{x,y}]++;
            freq[{y,x}]++;
            plus--;
            minus--;
        }
        int q;
        cin >> q;
        while(q--){
            int a, b;
            cin >> a >> b;
            int gcd = __gcd(a,b);
            a /= gcd;
            b /= gcd;
            if(freq[{a,b}] > 0){
                cout << "YES" << endl;
            } else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}