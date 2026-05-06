#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long int

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x, y, k;
        cin >> x >> y >> k;
        int sticks =  k + k * y;
        int trade = (sticks - 1) / (x - 1);
        if((sticks - 1) % (x - 1) != 0) trade++;
        trade += k;
        cout << trade << endl;
    }
    return 0;
}
