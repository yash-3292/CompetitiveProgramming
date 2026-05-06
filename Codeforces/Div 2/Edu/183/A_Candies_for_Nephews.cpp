#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = (3-n%3)%3;
        cout << ans << endl;
    }
    return 0;
}