#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(n == k){
            for(int i=0; i<n; i++) cout << 1;
            cout << endl;
            continue;
        }
        if(k == 0){
            for(int i=0; i<n; i++) cout << 0;
            cout << endl;
            continue;
        }
        int zero = n - k - 1;
        int one = k-1;
        cout << 1;
        for(int i=0; i<zero; i++) cout << 0;
        for(int i=0; i<one; i++) cout << 1;
        cout << 0;
        cout << endl;
    }
    return 0;
}