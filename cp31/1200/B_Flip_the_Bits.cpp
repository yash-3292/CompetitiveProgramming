#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a;
        string b;
        cin >> a;
        cin >> b;
        int one = 0;
        int zero = 0;
        if(a[0] == '0') zero++;
        else one++;
        int flag = 1;
        for(int i=1; i<n; i++){
            if((a[i] == b[i]) != (a[i-1] == b[i-1])){
                if(zero != one){
                    flag = 0;
                    break;
                }
            }
            if(a[i] == '0') zero++;
            else one++;
        } 
        if(a[n-1] != b[n-1]){
            if(zero != one){
                flag = 0;
            }
        }
        if(flag) cout << "YES" <<endl;
        else cout << "NO" << endl;
    }
    return 0;
}