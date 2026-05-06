#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; 
        int flag = 0;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x == 67) flag = 1;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}