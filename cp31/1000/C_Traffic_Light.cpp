#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        if(c == 'g'){
            cout << 0 << endl;
            continue;
        }
        int cnt = 0;
        int maxi = 0;
        char curr = 'g';
        for(int i=0; i<2*n-1; i++){
            if(curr == c){
                if(s[i%n] == 'g'){
                    maxi = max(maxi, cnt);
                    cnt = 0;
                    curr = 'g';
                } else{
                    cnt++;
                }
            } else{
                if(s[i%n] == c){
                    curr = c;
                    cnt++;
                }
            }
        }
        cout << maxi << endl;
    }
    return 0;
}
