#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int zero = 0;
        int one = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0') zero++;
            else one++;
        }
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0'){
                if(one == 0){
                    ans = zero;
                    break;
                }
                one--;
            }
            else{
                if(zero == 0){
                    ans = one;
                    break;
                }
                zero--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
