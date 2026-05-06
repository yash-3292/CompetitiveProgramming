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
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                int flag = 0;
                for(int j=i-1; j>=max(0,i-k+1); j--){
                    if(s[j] == '1'){
                        flag = 1;
                        break;
                    }
                }
                if(!flag) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}