#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    string s;
    cin >> s;
    int hour = (s[0]-'0') * 10 + (s[1]-'0');
    if(hour == 0){
        cout << 12 << s[2] << s[3] << s[4] << " AM" << endl;
        return;
    }
    if(hour < 12){
        cout << s << " AM" << endl;
        return;
    }
    if(hour > 12) hour -= 12;
    if(hour < 10){
        cout << "0" << hour << s[2] << s[3] << s[4] << " PM" << endl;
    } else{
        cout << hour << s[2] << s[3] << s[4] << " PM" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}