#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int sum = 0;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            sum += x;
        }
        if((sum%2 == 0) && ((n*k)&1)){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    }
    return 0;
}