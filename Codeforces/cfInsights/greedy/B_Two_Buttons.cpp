#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    while(n*(1<<cnt) < m){
        cnt++;
    }
    int ans = cnt;
    int diff = n*(1<<cnt) - m;
    while(cnt >=  0 && diff != 0){
        int x = 1<<cnt;
        ans += diff/x;
        diff %= x;
        cnt--;
    }
    cout << ans << endl;
    return 0;
}