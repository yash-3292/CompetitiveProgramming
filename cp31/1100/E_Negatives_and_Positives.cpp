#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll sum = 0;
        ll mini = 1e18;
        int cnt = 0;
        while(n--){
            ll num;
            cin >> num;
            sum += abs(num);
            if(num < 0) cnt++;
            mini = min(mini, abs(num));
        }
        if(cnt & 1) sum -= 2*mini;
        cout << sum << endl;
    }
    return 0;
}