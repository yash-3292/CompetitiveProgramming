#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int one = 0;
        int zero = 0;
        int question = 0;
        int flag = 1;
        for(int i=0; i<k; i++){
            int o = 0;
            int z = 0;
            int q = 0;
            for(int j=0; (i+j*k)<n; j++){
                if(s[i+j*k] == '1') o++;
                else if(s[i+j*k] == '0') z++;
                else q++;
            }
            if((o != 0) && (z != 0)){
                flag = 0;
                break;
            } else if(o != 0){
                one++;
            } else if(z != 0){
                zero++;
            } else{
                question++;
            }
        }
        if(!flag){
            cout << "NO" << endl;
            continue;
        }
        int val = abs(zero-one);
        if(question >= val) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}