#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll s1, s2, a, b;
        cin >> s1 >> s2 >> a >> b;
        if(a*s1*s1 < 2*b*b*(s1+s2)){
            cout << "Bolt" << endl;
        } else{
            cout << "Tiger" << endl;
        }
    }
    return 0;
}