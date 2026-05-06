#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        for(int i=1; i<=n; i++){
            int num = i^x;
            if(num > 0 && num <= n) cout << num << " ";
            else cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}