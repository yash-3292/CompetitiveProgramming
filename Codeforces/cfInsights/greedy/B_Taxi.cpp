#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int one = 0;
    int two = 0;
    int three = 0;
    int four = 0;
    while(n--){
        int x;
        cin >> x;
        if(x == 1) one++;
        else if(x == 2) two++;
        else if(x == 3) three++;
        else four++;
    }
    int ans = 0;
    int free = 0;
    ans += four;
    ans += three;
    free += three;
    ans += two/2;
    if(two&1){
        ans += 1;
        free += 2;
    }
    if(free < one){
        one -= free;
        ans += one/4 + (one%4 ? 1 : 0);
    }
    cout << ans << endl;
    return 0;
}