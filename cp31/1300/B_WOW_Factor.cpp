#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define cha first
#define cnt second

int main(){
    string s;
    cin >> s;
    int n = s.size();
    if(n == 1){
        cout << "0" << endl;
        return 0;
    }
    string temp;
    if(s[0] != 'v' || s[1] != 'o'){
        temp += s[0];
    }
    for(int i=1; i<n-1; i++){
        if((s[i] == 'v' && s[i-1] == 'o') && s[i+1] == 'o') continue;
        temp += s[i];
    }
    if(s[n-1] != 'v' || s[n-2] != 'o'){
        temp += s[n-1];
    }
    s = temp;
    n = s.size();
    vector<pair<char,ll>> arr;
    char ch = s[0];
    int cnt = 1;
    for(int i=1; i<n; i++){
        if(ch == s[i]) cnt++;
        else{
            if(ch == 'v'){
                arr.push_back(make_pair('w', (ll)(cnt-1)));
            } else{
                arr.push_back(make_pair(ch, (ll)cnt));
            }
            ch = s[i];
            cnt = 1;
        }
    }
    if(ch == 'v'){
        arr.push_back(make_pair('w', (ll)(cnt-1)));
    } else{
        arr.push_back(make_pair(ch, (ll)cnt));
    }
    int size = arr.size();
    ll sum = 0;
    for(int i=size-1; i>=0; i--){
        if(arr[i].cha == 'w') sum += arr[i].cnt;
        else arr[i].cnt *= sum;
    }
    ll ans = 0;
    sum = 0;
    for(int i=size-1; i>=0; i--){
        if(arr[i].cha == 'o') sum += arr[i].cnt;
        else ans += arr[i].cnt * sum;
    }
    cout << ans << endl;
    return 0;
}