#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i1 = -1;
        for(int i=0; i<n; i++){
            if(s[i] == ')'){
                i1 = i;
                break;
            }
        }
        int cnt = 0;
        for(int i=i1+1; i<n; i++){
            if(s[i] == '(') cnt++;
        }
        if(cnt >= 2) cout << n-2 << endl;
        else cout << -1 << endl;
    }
    return 0;
}