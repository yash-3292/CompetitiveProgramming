#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long int

bool fair(int n){
    int temp = n;
    while(temp != 0){
        int digit = temp % 10;
        temp /= 10;
        if(digit == 0) continue;
        if(n % digit != 0) return false;
    }
    return true;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        while(!fair(n)) n++;
        cout << n << endl;
    }
    return 0;
}
