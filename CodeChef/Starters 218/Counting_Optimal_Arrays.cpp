#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int temp = 1;
        if(n == 1){
            cout << m+1 << endl;
            continue;
        }
        while(temp <= m){
            temp *= 2;
        }
        int ans = (m+1) - (temp - (m+1));
        cout << ans << endl;
    }
    return 0;
}