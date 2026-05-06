#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(s == "++X" || s == "X++"){
            ans++;
        } else{
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}