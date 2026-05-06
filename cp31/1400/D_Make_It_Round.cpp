#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        int two = 0;
        int five = 0;
        int temp = (ll)n;
        while(temp % 5 == 0){
            two++;
            temp /= 5;
        }
        temp = (ll)n;
        while(temp % 2 == 0){
            five++;
            temp /= 2;
        }
        if(two > five){
            two = two - five;
            five = 0;
        } else if(two < five){
            five = five - two;
            two = 0;
        } else{
            two = 0;
            five = 0;
        }
        ll val = 1;
        for(int i=1; i<=two; i++){
            if(val * 2 <= m) val *= 2;
        }
        for(int i=1; i<=five; i++){
            if(val * 5 <= m) val *= 5;
        }
        while(val * 10 <= m){
            val *= 10;
        }
        ll mult = m/val;
        ll ans = mult*val;
        ans *= n;
        cout << ans << endl;
    }
}