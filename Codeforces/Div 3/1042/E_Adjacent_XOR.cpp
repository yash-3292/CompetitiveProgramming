#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        int flag = 1;
        for(int i=n-1; i>=0; i--){
            if(i == n-1){
                if(a[i] != b[i]){
                    flag = 0;
                    break;
                }
            } else{
                if(b[i] != (a[i]^a[i+1]) && b[i] != (a[i]^b[i+1]) && a[i] != b[i]){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}