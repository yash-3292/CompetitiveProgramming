#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        int val = 4*y + x;
        if(val%3 != 0){
            cout << "NO" << endl;
            continue;
        }
        val /= 3;
        if(val >= 2*y && val >= 0){
            cout << "YES" << endl; 
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}