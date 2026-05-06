#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int num = 2*n - 3;
        cout << num << endl;
        cout << 1 << " " << 1 << " " << n << endl;
        for(int i=2; i<=n; i++){
            if(i-1 != 1) cout << i << " " << 1 << " " << i-1 << endl;
            if(i != n) cout << i << " " << i << " " << n << endl;
        }
    }
    return 0;
}